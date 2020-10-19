// adapted from https://gist.github.com/capex/3863633

#include <stdio.h>

// function prototype
int gcd (int a, int b); 


int main(int argc, char const *argv[])
{
	int a, b, g;
	printf("Please enter a number: \n");
	scanf("%d", &a);

	printf("Please enter a number: \n");
	scanf("%d", &b);

	g = gcd (a,b);

	printf("The greatest common divisor of %d and %d is %d\n", a,b,g);

	return g;
}

int gcd (int a, int b) 
{
	int r; // remainder
	while (b > 0) 
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}
