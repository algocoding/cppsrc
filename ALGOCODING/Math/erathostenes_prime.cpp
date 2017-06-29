#include <stdio.h>
#include <math.h>
#define MAX 1000000
int prime[MAX + 1];		// 소인수 저장

void erathostenes(){
	for (int i = 2; i <= MAX; i++)
			prime[i] = i;

	int root = ceil(sqrt(MAX));

	for (int i = 2; i < root; i++)
	{
		if (prime[i] != i) continue;

		for (int j = i * i; j <= MAX; j += i)
		{
			if(prime[j] != j) continue;
			prime[j] = i;
		}
	}
}
int main()
{
	erathostenes();

	for (int i = 2; i <= 1000; i++)
	{
		if (prime[i] == i) printf("%d ", i);
	}
	return 0;
}
