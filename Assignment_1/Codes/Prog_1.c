#include <stdio.h>
long long int recursive_fact(long long int n)
{
	if (n <= 1)
		return 1;
	return n * recursive_fact(n - 1);
}
long long int iterative_fact(long long int n)
{
	long long int f = 1;
	int i;
	for (i = 2; i <= n; i++)
	{
		f *= i;
	}
	return f;
}
int main()
{
	long long int n = 20;
	printf("N = %d\n", n);
	long long int temp;
	temp = recursive_fact(n);
	printf("Fact(recursive) of %lld = %lld\n", n, temp);
	temp = iterative_fact(n);
	printf("Fact(iterative) of %lld = %lld\n", n, temp);
	n = 21;
	printf("\n\nN = %d\n", n);
	temp = recursive_fact(n);
	printf("Fact(recursive) of %lld = %lld\n", n, temp);
	temp = iterative_fact(n);
	printf("Fact(iterative) of %lld = %lld", n, temp);
}
