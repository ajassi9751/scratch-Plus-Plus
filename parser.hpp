// This file parses a json file and creates a data structure out of it
#include<stdio.h>
#include<string.h>

void parsejson(const char path[]) {
    FILE *fptr = fopen(path, "r");
    fseek(fptr, 0, SEEK_END);
    long length = ftell(fptr);
    rewind(fptr);
    char fbuff[length];
    fgets(fbuff,length,fptr);
}