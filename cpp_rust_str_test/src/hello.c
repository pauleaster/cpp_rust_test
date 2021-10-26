// Reference: https://github.com/alexcrichton/rust-ffi-examples

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int print_floats(char * str, size_t len);




int main(void)
{
    char * str  = "334.5 666.5 -123 3.1415926536";
    size_t len = strlen(str);
    printf("hello, World!\n");

    int ret =  print_floats(str, len);
    printf("Finished!!!!\n\n");
    return ret;
}