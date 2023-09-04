#include "stdio.h"

int main(int argc, char* argv[]) {
    printf("Number of arguments: %d\n", argc);
    if (argc == 2) {
        printf("%s\n", argv[1]);
        printf("%s\n", argv[1]);
        return 0;
    } else {
        printf("Wrong number of arguments.");
        return -1;
    }
}
