#pragma once
#include <vector>

class Integer
{
private:
    int _value {0};
    char *_buffer{nullptr};
public:
    Integer(int value);
    ~Integer();
    operator char*();
};
