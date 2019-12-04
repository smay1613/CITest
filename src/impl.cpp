#include "impl.h"
#include <stdio.h>

struct node {
    int freq {0};
    int pos {-1};
}node;
constexpr int ALPH_SIZE {26};
struct node buff[ALPH_SIZE] {};

int findpos (int pos){
    for(int i {0}; i < ALPH_SIZE; i++){
        if (buff[i].pos == pos)
        {
            return i;
        }
    }
    return -1;
}

void Decoder(const char key[],char message[]){
    int i {0};
    int c {0};
    int curPos {0};
    while (key[i] != 0)
    {
        c = key[i] - 'a';
        buff[c].freq++;
        if (buff[c].pos < 0)
        {
            buff[c].pos = curPos;
            curPos++;
        }
        i++;
    }

    for (i = 0; i < curPos; i++)
    {
        c = findpos(i);
        message[i] = '@' + buff[c].freq;
    }
}
