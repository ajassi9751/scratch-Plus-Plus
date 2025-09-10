// This file parses a json file and creates a data structure out of it
#include<stdio.h>
#include<cstring>

/*
@brief Finds a substring in a string and returns its position in said string
@param str The main string
@param substr The substring
@param instance Which occurence of the substring you want to find (the first time it appears, the second time it appears ect)
@return Returns an int of the position of the substring in the string, returns -1 if not found
*/
int findInStr (const char* str, const char substr[], int instance) {
    bool isTrue = false;
    int count = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == substr[0]) {
            for (int a = 1; a < strlen(substr); ++a) {
                if (str[i+a] == substr[a]) {
                    isTrue = true;
                }
                else {
                    isTrue = false;
                    break;
                }
            }
            count++;
            if (isTrue && count == instance) {
                return i;
            }
        }
    }
    return -1;
}

void parsejson(const char path[]) { //Could use the c++ style of doing this tho
    FILE *fptr = fopen(path, "r");
    fseek(fptr, 0, SEEK_END);
    long length = ftell(fptr);
    rewind(fptr);
    char fbuff[length];
    fgets(fbuff,length,fptr);
    // Creates a string with the contents of the whole file, this may be unviable for large files
    if (findInStr(fbuff, "variables", 1) != -1) {
        int flag = findInStr(fbuff, "variables", 1);
    }
}