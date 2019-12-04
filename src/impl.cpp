#include "impl.h"
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>

void Decoder(const char key[],char message[]) {
    int k = 0;
    char copy[ std::strlen(key)+1];
    strcpy( copy, key);
    for( int i = 0; key[i]; ++i) {
        if ( copy[i]) {
            for( int j = 0; key[j]; ++j) {
                if ( copy[i] == key[j]) {
                    message[k]++;
                }
            }
        }
    }
}




