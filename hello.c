/************************
   build with:
     gcc hello.c -o hello
   run with:
     ./hello
*************************/

#include <stdio.h>

int main() {

  for (int i=0; i<=0xA; i++)
    printf("Hello World!\n");

  return 0;
}

