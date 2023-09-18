#include "stdio.h"
int ex_1(void);
int ex_2(void);
int ex_3(void);
int ex_4(void);

int main(void) {
    printf("ex_1 = %d\n", ex_1());
    printf("ex_2 = %d\n", ex_2());
    printf("ex_3 = %d\n", ex_3());
    printf("ex_4 = %d\n", ex_4());
}


int ex_1(void) {
    int x = 10;
    int *p;
    p = &x;
    *p = 0;
    return x;
}

int ex_2(void) {
    int x = 10;
    int *p;
    int **pp;
    pp = &p;
    p = &x;
    **pp = 0;
    return x;
}

int ex_3(void) {
    int x = 10;
    int y = 10;

    int *p = &y;
    p = &x;
    *p = 0;
    p = &y;
    *p = 1;

    return x;
}

int ex_4(void) {
    int x = 10;
    //int y = 10; Not needed.
    int* arr[2];

    arr[0] = &x;
    arr[1] = arr[0];
    *(arr[1]) = 1;
    *(arr[0]) = *(arr[0]) - 1;

    return x;
}
