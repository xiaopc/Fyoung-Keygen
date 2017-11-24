#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "MD5.h"

void CalcRealID(const char* username, const char* password, unsigned int timestamp, char* out){
    const char* key = "aI0fC8RslXg6HXaKAUa6kpvcAXszvTcxYP8jmS9sBnVfIqTRdJS1eZNHmBjKN28j";
    unsigned char md5Result0[16], md5Result1[16];
    int v12, passwordASCIISum = 0;
    char passwordCheck[4+1], genkey0[64], pswFirst[64], pswSecond[64], genkey1[64], encrypt[256], finMD5[16+1];
    memset(passwordCheck,0,sizeof(passwordCheck));
    memset(genkey0,0,sizeof(genkey0));
    memset(pswFirst,0,sizeof(pswFirst));
    memset(pswSecond,0,sizeof(pswSecond));
    memset(genkey1,0,sizeof(genkey1));
    memset(finMD5,0,sizeof(finMD5));
    MD5_CTX md50, md51;

    for (int i = 0; i < strlen(password); i++) passwordASCIISum += *(password + i);

    v12 = (timestamp % strlen(password) < 1) + timestamp % strlen(password);
    sprintf(passwordCheck, "0%X", v12 ^ passwordASCIISum);
    
    encrypt[0] = (timestamp & 0xFF000000)>>24;
    encrypt[1] = (timestamp & 0x00FF0000)>>16;
    encrypt[2] = (timestamp & 0x0000FF00)>>8;
    encrypt[3] = (timestamp & 0x000000FF);
    memcpy(genkey0, key, (60 - (v12 + 1)));
    memcpy(pswFirst, password, (v12 + 1));
    memcpy(pswSecond, &password[v12 + 1], (strlen(password) - 1 - v12));
    memcpy(genkey1, key,(64 - strlen(username) - strlen(pswSecond)));
    sprintf(&encrypt[4], "%s%s%s%s%s", genkey0, pswFirst, username, genkey1, pswSecond);

    MD5Init(&md50);                 
    MD5Update(&md50,(unsigned char*)encrypt,128);
    MD5Final(&md50,md5Result0);
    MD5Init(&md51);                 
    MD5Update(&md51,md5Result0,16);
    MD5Final(&md51,md5Result1);
    for (int j=0; j<8; j++) sprintf(finMD5+2*j, "%02X", md5Result1[j]);

    sprintf(out, "~ghca%X%s%s%s%s", timestamp, "2023", finMD5, passwordCheck, username);
}

int main(int argc, char** argv){
    if (argc<3) return 0;
    if (strstr(argv[1], "tyfy") == NULL){
        printf("%s", argv[1]);
    } else {
        unsigned int timestamp = time((time_t*)NULL);
        char userID[48 + 1];
        memset(userID,0,sizeof(userID));
        CalcRealID(argv[1]+4,argv[2],timestamp,userID);
        printf("%s",userID);
    }
    return 0;
}