#include "impl.h"

void Decoder(const char key[],char message[])
{
    int ii = 0, jj = 0, n = 0, k = 0;
    int num[256] = {0};

    do
    {
        n++;
    }while(key[ii]);

    int  place[n]={0};

    for (ii=0; ii<n;ii++)
    {
        k = key[ii];
        num[k]++;
        if(!place[ii])
        {
            place[ii]++;
        }
    }

    ii = 0;
    do
    {
        if(place[ii])
        {
            k = key[ii];
            message[jj]='A'+num[k]-1;
            jj++;
        }
        ii++;
    }while(key[ii]);
    message[jj]='\0';
}
