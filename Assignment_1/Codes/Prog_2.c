#include <stdio.h>
long long int fibo(long long int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2); // the recursive call statement
}
long long int fibo_iterative(long long int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	long long int a = 0;
	long long int b = 1;
	n -= 2;
	while (n-- > 0) // iterative way to find the nth fibo no
	{
		long long int c = a + b;
		a = b;
		b = c;
	}
	return b;
}
int main()
{
	long long int n = 93;
	long long int temp = 0;
	temp = fibo(n);
	printf("N = %d", n);
	printf("\nUsing recursive method %dth fibonacci number = %d", n, temp);
	temp = fibo_iterative(n);
	printf("\nUsing iterative method %dth fibonacci number = %d", n, temp);

	n = 94;
	temp = fibo(n);
	printf("\n\nN = %d", n);
	printf("\nUsing recursive method %dth fibonacci number = %d", n, temp);
	temp = fibo_iterative(n);
	printf("\nUsing iterative method %dth fibonacci number = %d", n, temp);
}
