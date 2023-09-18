#include "stdio.h"

int main(int argc, char** argv) {
    if(argc > 2 || argc < 1) {
        return -1;
    }

    char* folder = argv[1];

    FILE* file = fopen(folder, "r");

    unsigned char c;
    while(fread(&c, sizeof(unsigned char), 1 , file)) {
        printf("%.2x\n", c);
    }

    return 0;
}
