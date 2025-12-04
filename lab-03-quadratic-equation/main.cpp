#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	double discriminant, root1, root2;

	printf("enter coefficients a, b and c:");
	scanf("%d %d %d", &a, &b, &c);

	// print equation
	printf("equation: %dx^2 + %dx + %d = 0\n", a, b, c);

	// discriminant

	discriminant = (b * b) - (4 * a * c);
	printf("discriminant: %.2f\n", discriminant);

	// if else
	if (discriminant > 0) {
		root1 = (-b + sqrt(discriminant)) / (2 * a);
		root2 = (-b - sqrt(discriminant)) / (2 * a);
		printf("roots are real and different.\n");
		printf("root1 = %.2f\n", root1);
		printf("root2 = %.2f\n", root2);

	}
	else if (discriminant = 0) {
		root1 = -b / (2.0 * a);

		printf("roots are real and same.\n");
		printf("root 1 = root 2 = %.2f\n", root1);
	}
	
	else {
		printf("the equation has no real roots.\n");
	}

	return 0;
}


