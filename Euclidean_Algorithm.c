#include <stdio.h>
#include <stdlib.h>

main() {
	/*	Function prototypes	*/
	unsigned FindGCD(unsigned a, unsigned b, FILE *outputFile);	// Takes two unsignedegers and returns their GCD

	/*	Variables	*/
	unsigned a = 100;
	unsigned b = 101;
	unsigned result;
	FILE *outputFile = fopen("Euclidean.tex", "w");

	fprintf(outputFile, "\\begin{align*}\n");
	result = FindGCD(a, b, outputFile);
	fprintf(outputFile, "\\end{align*}\n");

	fprintf(outputFile, "The last nonzero remainder is \(%d\).\\\\\n", result);
	fprintf(outputFile, "So the GCD of $%d$ and $%d$ is \\highlight{\(%d\)}.", a, b, result);
	printf("%d\n", result);

	exit(EXIT_SUCCESS);
}

/*	Find the greatest common divisor of a and b	*/
unsigned FindGCD(unsigned a, unsigned b, FILE *outputFile) {
	unsigned r;

	// Guarantee that a > b
	if(a < b) {
		r = a;
		a = b;
		b = r;
	}

	fprintf(outputFile, "%d &= %d * %d", a, b, a/b);
	r = a % b;
	if(r == 0) {
		fprintf(outputFile, " + %d\n", r);
		return(b);
	}
	else {
		fprintf(outputFile, " + %d\\\\\n", r);
		return(FindGCD(b, r, outputFile));
	}
}
