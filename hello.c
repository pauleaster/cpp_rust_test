#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_floats(char * string_of_floats) {

    char * pEnd, * pStart;
    float f1;
    pStart = string_of_floats;
    pEnd = string_of_floats;
    int len = strlen(string_of_floats);
    int char_size = sizeof(char);
    while (1) {
        printf("Before: %p %p\n",pStart,pEnd);
        f1 = strtof(pStart,&pEnd); // if no result then pStart == pEnd
        if (pEnd == pStart) {
            printf("Breaking, index=%d, length = %d\n",(pEnd - string_of_floats)/char_size,len);
            return (1);
        }
        printf("%0.5f\n",f1);
        printf("After: %p %p\n\n",pStart,pEnd);
        pStart = pEnd; // Move the starting position to the end of the last read

    }
}



int main(void)
{
    char * str  = "334.5 666.5 -123 3.1415926536";
    printf("hello, World!\n");

    return print_floats(str);
}