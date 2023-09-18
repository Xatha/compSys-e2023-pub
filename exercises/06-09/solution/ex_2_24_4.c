#include "stdio.h"

int main(void) {
	int acc = 0;
	int i = 10;

LOOP:
	if (i < 0) {
		goto DONE;
	} else {
		i--;
		acc += 2;
		goto LOOP;
	}

DONE:
	printf("%d", acc);

	return acc;
}