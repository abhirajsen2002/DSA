#include <stdio.h>
int recursive_fact(int n)
{
	if (n <= 1)
		return 1;
	return n * recursive_fact(n - 1);
}
int iterative_fact(int n)
{
	int f = 1;
	int i;
	for (i = 2; i <= n; i++)
	{
		f *= i;
	}
	return f;
}
int main()
{
	int n = 13;
	printf("N = %d\n", n);
	int temp;
	temp = recursive_fact(n);
	printf("Fact(recursive) of %d = %d\n", n, temp);
	temp = iterative_fact(n);
	printf("Fact(iterative) of %d = %d", n, temp);
}