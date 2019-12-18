#pragma once

#include <map>

class Integer {
private:
    int _value;
//    char* _buffer { nullptr };

public:
    Integer(int value);
    ~Integer();
    operator char*();
};
