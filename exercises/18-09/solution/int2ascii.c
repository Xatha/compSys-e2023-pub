#include "stdio.h"

int read_int(FILE* file, int *out);

int main(int argc, char** argv) {
    if(argc != 2) {
        return -1;
    }

    char* folder = argv[1];

    FILE* file = fopen(folder, "r");

    int i;
    while(read_int(file, &i)) {
        printf("%d\n", i);
    }
}

int read_int(FILE* file, int *out) {
    return fread(out, sizeof(int), 1, file);
}
