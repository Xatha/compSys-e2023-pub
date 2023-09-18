#include "stdio.h"
#include "assert.h"

int read_ascii_int(FILE* file, int* out);

int main(int argc, char** argv) {
    assert(argc == 3);

    FILE* read_file = fopen(argv[1], "r");
    FILE* write_file = fopen(argv[2], "w");

    assert(read_file != NULL);
    assert(write_file != NULL);

    int i;

    while(read_ascii_int(read_file, &i) == 0) {
        printf("Found and writing: %d\n", i);
        assert(fwrite(&i, sizeof(int), 1, write_file) == 1);
    }

    return 0;
}

int read_ascii_int(FILE* file, int* out) {
    char c;

    int result = 0;

    while(fread(&c, sizeof(char), 1, file) != 0) { // 10 = '/n'
        if ('0' <= c && c <= '9') {
            result = result * 10 + (c - '0');
        } else if (c == '\n') {
            *out = result;
            return 0;
        } else {
            return 1; // FAILURE
        }
    }

    return 1;
}
