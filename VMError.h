#pragma once

#include <string>

class VMError {
    public:
        VMError(std::string error){
            static int32_t errorCode = 0;

            this->error = error;
            this->code = ++errorCode;
        };

        std::string error;
        int32_t code;
};