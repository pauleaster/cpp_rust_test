#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
    char * str  = "334.5 666.5 -123 3.1415926536";
    char * pEnd, * pStart;
    printf("hello, World!\n");
    float f1;
    pStart = str;
    pEnd = str;
    while (1) {
        printf("Before: %p %p\n",pStart,pEnd);
        f1 = strtof(pStart,&pEnd); // if no result then pStart == pEnd
        if (pEnd == pStart) {
            break;
        }
        printf("%0.5f\n",f1);
        printf("After: %p %p\n\n",pStart,pEnd);
        pStart = pEnd; // Move the starting position to the end of the last read

    }

    return 0;
}