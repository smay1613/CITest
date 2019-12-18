#include "impl.h"
#include <exception>
#include <map>
#include <string>
#include <iostream>

Integer::Integer(int value)
{
    if ((0 <= value) &&(10 >= value)) {
        std::map<int, std::string> mapOfNum {{0, "zero"},
                                             {1, "one"},
                                             {2, "two"},
                                             {3, "three"},
                                             {4, "four"},
                                             {5, "five"},
                                             {6, "six"},
                                             {7, "seven"},
                                             {8, "eight"},
                                             {9, "nine"},
                                             {10, "ten"}};
        auto it = mapOfNum.begin();
        while (it != mapOfNum.end()) {
            if (it->first == value){
                _buffer = const_cast<char*>(it->second.c_str());
                break;
            }
            it++;
        }
    }
    else
    {
        std::cout << "Integer out of boundaries\n";
    }
}
Integer::~Integer()
{
}

Integer::operator char*()
{
    return _buffer;
}
