//cl /EHsc /sdl /W4 /TC hello.c
/* SDL = additional security checks
TC = C 
TP = C++
   /W4 = /W4 displays level 1, level 2, and level 3 warnings, and all level 4 (informational) warnings that aren't off by default. 
   We recommend that you use this option to provide lint-like warnings. For a new project, it may be best to use /W4 in all compilations. 
   This option helps ensure the fewest possible hard-to-find code defects.
*/

#include <stdio.h>
#include <stdlib.h>

int printAlternative()
{
    //Supplying printf with user input can lead to a security vulnerability 
    if (printf("Secure programming") < 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(void) {
    if (puts("Hello, world.\nTime to learn secure programming!") == EOF) {
        return EXIT_FAILURE;
        //In the event put reaches the end of file 1 will be returned
    }
    printAlternative();
    return EXIT_SUCCESS;
}

