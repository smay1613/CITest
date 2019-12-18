#include "impl.h"
#include <exception>
#include <stdexcept>

Integer::Integer(int value):_value(value)
{
    if ((value>=0) && (value<10))
    {    std::vector<char*> literalNumbers {"zero",
                                       "one",
                                       "two",
                                       "three",
                                       "four",
                                       "five",
                                       "six",
                                       "seven",
                                       "eight",
                                       "nine"};
        _buffer = const_cast<char*> (literalNumbers[value]);
    }
    else
    {
        throw std::out_of_range ("wrong value");
    }
}

Integer::~Integer()
{
}

Integer::operator char *()
{
    return _buffer;
}
