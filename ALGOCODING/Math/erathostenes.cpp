#include <stdio.h>
#define MAX 1000000
bool prime[MAX + 1];

void erathostenes(){
	for (int i = 2; i <= MAX; i++)
			prime[i] = true;

		int sqrt;
		for (sqrt = 2; sqrt < MAX; sqrt++)
			if (sqrt * sqrt > MAX) break;

		for (int i = 2; i < sqrt; i++)
		{
			if (prime[i])
			{
				for (int j = i * i; j < MAX; j += i)
					prime[j] = false;
			}
		}
}
int main()
{
	erathostenes();

	for (int i = 2; i <= 1000; i++)
	{
		if (prime[i]) printf("%d ", i);
	}
	return 0;
}
