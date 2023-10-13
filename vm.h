#ifndef VM_H
#define VM_H

#include "tests/tests-enabled.h"
#include "VMError.h"

#include <iostream>
#include <cstdint>
#include <vector>
#include <chrono>

class VM {
    public:    

    static const int32_t REGISTER_COUNT = 4;
    
    VM(int32_t memorySize = 0);

    void loadFromFile(std::string filename, bool skim = true);
    void loadFromMemory(const std::vector<int32_t> &memory, bool skim = true);
    void skim();
    
    inline void checkAddress(int32_t address, bool allowStack = false){        
        if(address < (this->programProtected? this->dataStartIndex : 0) || address >= (allowStack? this->memorySize : (this->stackProtected? this->stackStartIndex : this->memorySize))){
            throw VM::ERROR_ADDRESS_OUT_OF_DATA_BOUNDS;
        }
    }

    inline void checkRegister(int32_t _register){        
        if(_register < 0 && _register >= VM::REGISTER_COUNT){
            throw VM::ERROR_INVALID_REGISTER;
        }
    }

    inline void setMem(int32_t address, int32_t value, bool allowStack = false){        
        this->checkAddress(address, allowStack);

        this->memory[address] = value;
    }

    inline int32_t getMem(int32_t address, bool allowStack = false){
        this->checkAddress(address, allowStack);

        return this->memory[address];
    }

    inline void setReg(int32_t _register, int32_t value){            
        this->checkRegister(_register);

        this->registers[_register] = value;
    }

    inline int32_t getReg(int32_t _register){        
        this->checkRegister(_register);

        return this->registers[_register];
    }

    inline int32_t getControl(){        
        return this->control;
    }

    inline void setControl(int32_t address){
        if(address < 0 || address >= this->dataStartIndex){
            throw VM::ERROR_ADDRESS_OUT_OF_PROGRAM_BOUNDS;
        }

        this->control = address;
    }

    inline void setProgramProtection(bool on){
        this->programProtected = on;
    }

    inline void setStackProtection(bool on){
        this->stackProtected = on;
    }

    void setFlags(int16_t flags, bool setOverflow = true){        
        this->flagZero =     0x0040 & flags;
        this->flagSign =     0x0080 & flags;
        if(setOverflow){
            this->flagOverflow = 0x0800 & flags;
        }
    }

    inline void pushStack(int32_t value){        
        this->setMem(this->stack, value, true);     
        this->stackLength++;
        this->stack++;
    }

    inline int32_t popStack(){        
        if(this->stackLength == 0){
            throw VM::ERROR_STACK_UNDERFLOW;
        }

        this->stackLength--;
        this->stack--;
        return this->getMem(this->stack, true);
    }

    inline int32_t *getMemory(){        
        return this->memory.data();
    }

    inline int32_t getStackLength(){
        return this->stackLength;
    }

    inline int32_t *getStack(){
        return this->memory.data() + this->stack;
    }

    void interrupt(int32_t value, int32_t systemCallNumber, int32_t messageLength, int32_t messagePtr, int32_t fileDescriptor);

    void flushStdin();

    #ifndef TESTS
    void run();
    #else
    void run(int32_t steps);
    #endif
    void dump();

    inline int32_t getExecutionTime(){
        const std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - this->start;
        return std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1, 1000>>>(diff).count();
    }

    bool flagZero = true;
    bool flagSign = false;
    bool flagOverflow = false;

    static const VMError ERROR_MEMORY_TOO_LOW;
    static const VMError ERROR_ADDRESS_OUT_OF_DATA_BOUNDS;
    static const VMError ERROR_ADDRESS_OUT_OF_PROGRAM_BOUNDS;
    static const VMError ERROR_INVALID_REGISTER;
    static const VMError ERROR_STACK_UNDERFLOW;
    static const VMError ERROR_INVALID_INTERRUPT;
    static const VMError ERROR_INVALID_SYS_CALL;
    static const VMError ERROR_NEGATIVE_LENGTH;
    static const VMError ERROR_DIVISION_BY_ZERO;
    static const VMError ERROR_CLOCK_NOT_STEADY;
    static const VMError ERROR_FILE_OPEN;
    static const VMError ERROR_FILE_READ_1;
    static const VMError ERROR_FILE_READ_2;
    static const VMError ERROR_FILE_READ_3;
    static const VMError ERROR_FILE_READ_4;
    static const VMError ERROR_FILE_READ_5;
    static const VMError ERROR_FILE_READ_6;
    static const VMError ERROR_FILE_READ_7;
    static const VMError ERROR_FILE_INVALID_1;
    static const VMError ERROR_MEMORY_INVALID_1;
    static const VMError ERROR_FILE_INVALID_2;
    static const VMError ERROR_FILE_INVALID_3;
    static const VMError ERROR_MEMORY_INVALID_3;
    static const VMError ERROR_FILE_INVALID_4;
    static const VMError ERROR_FILE_INVALID_5;
    static const VMError ERROR_MEMORY_INVALID_5;
    static const VMError ERROR_FILE_INVALID_6;
    static const VMError ERROR_FILE_INVALID_7;
    static const VMError ERROR_FILE_INVALID_8;
    static const VMError ERROR_FILE_INVALID_9;
    static const VMError ERROR_RUNTIME_INVALID_MICROCODE;
    static const VMError ERROR_IMPLEMENTATION;

    #ifdef TESTS
    bool flushed = false;
    #endif

    private:
    std::vector<int32_t> memory;
    std::string stdinBuffer;
    int32_t memorySize;
    int32_t dataStartIndex;
    int32_t stackStartIndex;
    int32_t stack;
    int32_t stackLength = 0;
    int32_t control = 0;
    int32_t registers[VM::REGISTER_COUNT];
    bool programProtected = true;
    bool stackProtected = true;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

    void postLoad(int32_t programSize);
    int32_t waitForInput(int32_t address, int32_t length);
};

#endif