#include "vm.h"

#include <iostream>
#include <fstream>
#include <iomanip>

#include "helper.h"
#include "instructions.h"

const VMError VM::ERROR_MEMORY_TOO_LOW = VMError("Set memory amount for virtual machine is too low to run specified program.");
const VMError VM::ERROR_ADDRESS_OUT_OF_DATA_BOUNDS = VMError("Memory address out of bounds of data memory.");
const VMError VM::ERROR_ADDRESS_OUT_OF_PROGRAM_BOUNDS = VMError("Memory address out of bounds of program memory.");
const VMError VM::ERROR_INVALID_REGISTER = VMError("Invalid register.");
const VMError VM::ERROR_STACK_UNDERFLOW = VMError("Stack underflow.");
const VMError VM::ERROR_INVALID_INTERRUPT = VMError("Invalid interrupt, 0x80 is only supported interrupt.");
const VMError VM::ERROR_INVALID_SYS_CALL = VMError("Invalid system call number. Supported are 4 and 3.");
const VMError VM::ERROR_NEGATIVE_LENGTH = VMError("System call length argument cannot be negative.");
const VMError VM::ERROR_DIVISION_BY_ZERO = VMError("Division by 0.");
const VMError VM::ERROR_CLOCK_NOT_STEADY = VMError("High resolution clock is not steady.");
const VMError VM::ERROR_FILE_OPEN = VMError("Failed to open program file.");
const VMError VM::ERROR_FILE_READ_1 = VMError("Failed to read program file #1.");
const VMError VM::ERROR_FILE_READ_2 = VMError("Failed to read program file #2.");
const VMError VM::ERROR_FILE_READ_3 = VMError("Failed to read program file #3.");
const VMError VM::ERROR_FILE_READ_4 = VMError("Failed to read program file #4.");
const VMError VM::ERROR_FILE_READ_5 = VMError("Failed to read program file #5.");
const VMError VM::ERROR_FILE_READ_6 = VMError("Failed to read program file #6.");
const VMError VM::ERROR_FILE_READ_7 = VMError("Failed to read program file #7.");
const VMError VM::ERROR_FILE_INVALID_1 = VMError("File does not seem to be valid program. Size less than 9 bytes.");
const VMError VM::ERROR_MEMORY_INVALID_1 = VMError("Memory does not seem to be valid program. Size less than 2 int32 values.");
const VMError VM::ERROR_FILE_INVALID_2 = VMError("File does not seem to be valid program. Invalid file header.");
const VMError VM::ERROR_FILE_INVALID_3 = VMError("File does not seem to be valid program. Invalid data memory start position.");
const VMError VM::ERROR_MEMORY_INVALID_3 = VMError("Memory does not seem to be valid program. Invalid data memory start position.");
const VMError VM::ERROR_FILE_INVALID_4 = VMError("File does not seem to be valid program. Program size is not dividable by 4.");
const VMError VM::ERROR_FILE_INVALID_5 = VMError("File does not seem to be valid program. No halt instruction found before data memory start position.");
const VMError VM::ERROR_MEMORY_INVALID_5 = VMError("Memory does not seem to be valid program. No halt instruction found before data memory start position.");
const VMError VM::ERROR_FILE_INVALID_6 = VMError("File does not seem to be valid program. Skiming program failed #1.");
const VMError VM::ERROR_FILE_INVALID_7 = VMError("File does not seem to be valid program. Skiming program failed #2.");
const VMError VM::ERROR_FILE_INVALID_8 = VMError("File does not seem to be valid program. Skiming program failed #3.");
const VMError VM::ERROR_FILE_INVALID_9 = VMError("File does not seem to be valid program. Skiming program failed, last instruction is not halt instruction.");
const VMError VM::ERROR_RUNTIME_INVALID_MICROCODE = VMError("Invalid instruction code encountered during execution of the program.");
const VMError VM::ERROR_IMPLEMENTATION = VMError("Encountered instruction with unsupported arguments count.");


VM::VM(int32_t memorySize){
    if(!std::chrono::high_resolution_clock::is_steady){
        throw VM::ERROR_CLOCK_NOT_STEADY;
    }

    this->memorySize = memorySize;
}

void VM::loadFromMemory(const std::vector<int32_t> &memory, bool skim){
    if(memory.size() < 2){
        throw VM::ERROR_MEMORY_INVALID_1;
    }

    int32_t programSize = memory.size() - 1;

    if(memorySize == 0){
        memorySize = programSize * 1.1 + 128;
    } else if(memorySize < programSize){
        throw VM::ERROR_MEMORY_TOO_LOW;
    }

    this->dataStartIndex = memory[0];
    
    if(this->dataStartIndex > programSize){
        throw VM::ERROR_MEMORY_INVALID_3;
    }

    if(memory[this->dataStartIndex] != 0){
        throw VM::ERROR_MEMORY_INVALID_5;
    }

    this->memory = std::vector<int32_t>(memorySize);
    const int32_t *programMemory = memory.data() + 1;
    const int32_t *programMemoryEnd = memory.data() + memory.size();
    int32_t *vmMemoryPtr = this->memory.data();

    while(programMemory != programMemoryEnd){
        *(vmMemoryPtr++) = *(programMemory++);
    }

    if(skim){
        this->skim();
    }

    this->postLoad(programSize);
}

void VM::loadFromFile(std::string filename, bool skim){
    std::ifstream file(filename, std::ios::binary | std::ios::in);
    if(!file.is_open()){
        throw VM::ERROR_FILE_OPEN;
    }

    if(!static_cast<bool>(file.seekg(0, std::ios::end))){
        throw VM::ERROR_FILE_READ_1;
    }

    std::streampos fileSize = file.tellg();
    if(fileSize == -1){
        throw VM::ERROR_FILE_READ_2;
    }

    if(!static_cast<bool>(file.seekg(0, std::ios::beg))){
        throw VM::ERROR_FILE_READ_3;
    }

    if(fileSize < 9){
        throw VM::ERROR_FILE_INVALID_1;
    }

    std::streampos programSize = fileSize - std::streamoff(8);

    if(programSize % 4 != 0){
        throw VM::ERROR_FILE_INVALID_4;
    }

    programSize = programSize / 4;

    if(memorySize == 0){
        memorySize = programSize * 1.1 + 128;
    } else if(memorySize < programSize){
        throw VM::ERROR_MEMORY_TOO_LOW;
    }

    this->memory = std::vector<int32_t>(memorySize);

    std::vector<char> magic(4);    
    if(!static_cast<bool>(file.read(magic.data(), 4))){
        throw VM::ERROR_FILE_READ_4;
    }

    if(magic[0] != 'K' || magic[1] != 'A' || magic[2] != 's' || magic[3] != 'm'){
        throw VM::ERROR_FILE_INVALID_2;
    }

    if(!static_cast<bool>(file.read(reinterpret_cast<char *>(&this->dataStartIndex), 4))){
        throw VM::ERROR_FILE_READ_5;
    }
    
    if(this->dataStartIndex > programSize){
        throw VM::ERROR_FILE_INVALID_3;
    }

    if(!static_cast<bool>(file.read(reinterpret_cast<char *>(this->memory.data()), this->dataStartIndex * 4))){
        throw VM::ERROR_FILE_READ_6;
    }

    if(*(this->memory.data() + this->dataStartIndex - 1) != 0){
        throw VM::ERROR_FILE_INVALID_5;
    }

    if(skim){
        this->skim();
    }

    if(!static_cast<bool>(file.read(reinterpret_cast<char *>(this->memory.data() + this->dataStartIndex), programSize * 4 - std::streamoff(this->dataStartIndex * 4)))){
        throw VM::ERROR_FILE_READ_7;
    }

    file.close();

    this->postLoad(programSize);
}

void VM::postLoad(int32_t programSize){
    for(int32_t i = 0; i < VM::REGISTER_COUNT; i++){
        this->registers[i] = 0;
    }

    this->stackStartIndex = programSize;
    this->stack = programSize;
}

void VM::skim(){    
    int32_t *program = this->memory.data();
    int32_t *programEnd = program + this->dataStartIndex;
    bool ok = false;
    //std::cout << this->dataStartIndex << std::endl;
    while(program != programEnd){
        int32_t microcode = *program;
        if(microcode == 0){
            program++;
            if(program != programEnd){
                throw VM::ERROR_FILE_INVALID_6;
            }
            ok = true;
            break;
        } else if(microcode < 0 || microcode > Instructions::MICROCODE_MAX){
            throw VM::ERROR_FILE_INVALID_7;
        }

        //std::cout << reinterpret_cast<char*>(Instructions::BY_MICROCODE[microcode][2]) << " " << Instructions::BY_MICROCODE[microcode][1] << " " << (((int)(program - this->memory.data())) ) <<  std::endl;

        program += Instructions::BY_MICROCODE[microcode][1];
        if(program > programEnd){                
            throw VM::ERROR_FILE_INVALID_8;
        }
    }

    if(!ok){
        throw VM::ERROR_FILE_INVALID_9;
    }
}

void VM::interrupt(int32_t value, int32_t systemCallNumber, int32_t messageLength, int32_t messagePtr, int32_t fileDescriptor){
    if(value != 0x80){
        throw VM::ERROR_INVALID_INTERRUPT;
    }

    if(systemCallNumber != 3 && systemCallNumber != 4){
        throw VM::ERROR_INVALID_SYS_CALL;
    }

    if(messageLength == 0){
        return;
    }

    if(messageLength < 0){
        throw VM::ERROR_NEGATIVE_LENGTH;
    }

    if(fileDescriptor < 0 && fileDescriptor > 2){ //If not stdint/stdout/stderr
        return;
    }

    //Probe start and end memory addresses to eventually trigger exception
    //for sys_read do not check memory addresses if pointer is null
    if(systemCallNumber == 4 || messagePtr != 0){
        this->checkAddress(messagePtr);
        this->checkAddress(messagePtr + messageLength - 1);
    }

    if(systemCallNumber == 3){/*
        if(stdinBuffer.length() == 0){
            std::string input;
            std::getline(std::cin, input);
            this->stdinBuffer = input;
        }

        if(stdinBuffer.length() <= messageLength){
            int32_t *memoryPtr = this->getMemory() + messagePtr;
            const char *stringPtr = this->stdinBuffer.c_str();
            const char *stringEnd = stringPtr + this->stdinBuffer.length();
            while(stringPtr != stringEnd){
                *(memoryPtr++) = *(stringPtr++);
            }

            this->stdinBuffer = std::string("");
        } else {
            std::string stringSlice = this->stdinBuffer.substr(0, messageLength);

            int32_t *memoryPtr = this->getMemory() + messagePtr;
            const char *stringPtr = stringSlice.c_str();
            const char *stringEnd = stringPtr + stringSlice.length();
            while(stringPtr != stringEnd){
                *(memoryPtr++) = *(stringPtr++);
            }
            
            this->stdinBuffer = this->stdinBuffer.substr(messageLength);
        }*/

        this->setReg(0, waitForInput(messagePtr, messageLength));
    } else {
        int32_t *sliceBegin = this->getMemory() + messagePtr;
        int32_t *sliceEnd = sliceBegin + messageLength;        
        std::cout << UnicodeToUTF8(sliceBegin, sliceEnd);
        this->setReg(0, messageLength); //eax
    }
}

int32_t VM::waitForInput(int32_t address, int32_t length){
    if(length == 0){
        return 0;
    }
    
    char ch;
    std::cin.get(ch);

    *(this->memory.data() + address) = ch;

    if(length == 1){
        return 1;
    }

    std::vector<char> buff(length - 1);

    std::streamsize count = std::cin.readsome(buff.data(), buff.size());

    int32_t *slice = this->memory.data() + address + 1;    
    char *buffPtr = buff.data();
    char *buffEnd = buffPtr + buff.size();

    while(buffPtr != buffEnd){
        *(slice++) = *(buffPtr++);
    }

    return count + 1;
}

void VM::flushStdin(){
    static std::vector<char> buff(8192);
    while(std::cin.readsome(buff.data(), 8192) > 0);
    #ifdef TESTS
    this->flushed = true;
    #endif
}

#ifndef TESTS
void VM::run(){
#else
void VM::run(int32_t steps){
    int32_t step = 0;
#endif
    int32_t microcode;
    int32_t *program = this->memory.data();
    int32_t *programControl;
    const intptr_t *instruction;

    this->start = std::chrono::high_resolution_clock::now();

    while(true){
        programControl = program + this->control;
        microcode = *programControl;
        if(microcode == 0){
            return;
        }

        if(microcode < 0 || microcode > Instructions::MICROCODE_MAX){
            throw VM::ERROR_RUNTIME_INVALID_MICROCODE;
        }

        instruction = Instructions::BY_MICROCODE[microcode];         
        this->control += *(instruction + 1);

        //std::cout << "(" << microcode << ")[" << *(instruction + 1) << "] " << reinterpret_cast<const char*>(*(instruction + 2)) << " ";

        switch(*(instruction + 1)){
            case 1:
                reinterpret_cast<void(*)(VM &)>(*instruction)(*this);                                
                break;

            case 2:
                //std::cout << "[" << *(programControl + 1) << "]";
                reinterpret_cast<void(*)(VM &, int32_t)>(*instruction)(*this, *(programControl + 1));
                break;

            case 3:
                //std::cout << "[" << *(programControl + 1) << "], [" << *(programControl + 2) << "]";
                reinterpret_cast<void(*)(VM &, int32_t, int32_t)>(*instruction)(*this, *(programControl + 1), *(programControl + 2));
                break;

            default:
                throw VM::ERROR_IMPLEMENTATION;
        }

        //std::cout << std::endl;
        #ifdef TESTS
        if(steps != 0 && ++step == steps){
            return;
        }
        #endif
    }
}

void VM::dump(){
    std::cout << std::setw(24) << this->getReg(0) << std::setw(12) << this->getReg(1) << std::setw(12) << this->getReg(2) << std::setw(12) << this->getReg(3);
    std::cout << std::setw(12) << (std::string("ZF: ") + (this->flagZero? "1" : "0")) << std::setw(12) << (std::string("SF: ") + (this->flagSign? "1" : "0")) << std::setw(12) << (std::string("OF: ") + (this->flagOverflow? "1" : "0")) << std::endl;
    
    int i = 0;
    std::cout << std::setw(11) << " " << " _";
    for(int i = 0; i < 16; i++){
        std::cout << std::setfill('_') << std::setw(6) << i << "_____ ";
    }
    std::cout << std::endl << std::setfill('_') << std::setw(10) << i << "_|" << std::setfill(' ');

    for(auto it = this->memory.cbegin(); it != this->memory.cend(); ++it, ++i){        
        std::cout << std::setw(12) << *it;
        if(i % 16 == 15){
            std::cout << std::endl << std::setfill('_') << std::setw(10) << (i + 1) << "_|" << std::setfill(' ');
        }            
    }

    std::cout << std::endl;
}