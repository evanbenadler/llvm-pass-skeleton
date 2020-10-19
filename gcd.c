// adapted from https://gist.github.com/capex/3863633

#include <stdio.h>
#include "annotation_preserve_printf.h"

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

  __preserve_printf();
  printf("The greatest common divisor of %d and %d is %d\n", a,b,g);
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
