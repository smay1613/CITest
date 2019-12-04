#include "impl.h"
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>

void Decoder(const char key[],char message[]) {
    int k = 0;
    strcpy( message, key);
    for( int i = 0; key[i]; ++i) {
            char cmp = message[i];
            if ( cmp != ' ') {
                message[k] = 'A';
                for( int j = i+1; message[j]; ++j) {
                    if ( cmp == message[j]) {
                        message[k]++;
                        message[j] = ' ';
                    }
                }
                k++;
            }
    }
    message[k] = '\0';
}




