#include "impl.h"

char* IntToBinaryRepresentation(char* bufer, int source) {
    constexpr int sz = sizeof(int) *8;
    for (int i=0; i< sz; i++) {
        bufer[sz-i -1]= '0' + source ^ ((source >> 1) << 1);
        source>>= 1;
    }
    bufer[sz] = '\0';
    return bufer;
}
