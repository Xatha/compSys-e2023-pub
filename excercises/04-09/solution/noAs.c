#include "stdio.h"

int main(int argc, char* argv[]) {
    if (2 > argc) {
        printf("No arguments given.\n");
    } else {
        for (int i = 1; i < argc; i++) {
            char* string = argv[i];

            if ('A' == string[0]) {
                printf("No beginning A's are allowed\n");
            } else {
                printf("%s\n", string);
            }
        }
    }

    return 0;
}
