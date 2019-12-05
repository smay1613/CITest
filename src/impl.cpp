#include "impl.h"
#include <string.h>

//void ToBase64(char *strIn,char *strOut)
//{

//}


void Decoder(const char key[],char message[]) {
    int outputInd = 0;
    for (int inputArrInd = 0; key[inputArrInd]; inputArrInd++) {
        int i = -1;
        // check if letter is not calculated before
        for (i = inputArrInd - 1; i >= 0; i--) {
            if (key[i] == key[inputArrInd]) {
                break;
            }
        }

        if (i < 0) { /* index is not calculated previously */
            // calculate frequency of the letter
            int counter = 0;
            for (int j = inputArrInd; key[j]; j++) {
                if (key[inputArrInd] == key[j]) {
                    counter++;
                }
            }
            message[outputInd++] = 'A' + counter - 1;
        }
    }
    message[outputInd] = '\0';
}

