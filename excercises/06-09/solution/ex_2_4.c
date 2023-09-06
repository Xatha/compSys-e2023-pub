int main (void) {
	int f = 0, g = 0;

	int A[20] = { 0 };
	int B[20] = { 0 };

	B[g] = A[f + 1] + A[f];
	return B[0]; //Return B[0] so we don't get errors because we have unused variables.
}