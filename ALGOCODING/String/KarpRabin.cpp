/*
 * KarpRabin.cpp
 *
 *  Created on: 2017. 7. 9.
 *      Author: JongYun, Jung
 */

#include <stdio.h>
const int PRIME = 977;
const int d = 10;

int KarpRabin(char t[], char p[])
{
	int n = 0, m = 0, th = 0, ph = 0, k = 1;
	while (t[n]) n++;
	while (p[m]) m++;

	for (int i = 0; i < m - 1; i++)
		k = (k * d) % PRIME;

	for (int i = 0; i < m; i++)
	{
		th = ((th * d) + t[i]) % PRIME;
		ph = ((ph * d) + p[i]) % PRIME;
	}
	for (int i = 0; i <= n - m; i++)
	{
		if (th == ph) {		// 해시 충돌 주의
			int j;
			for (j = 0; j < m; j++)
			{
				if (t[i + j] != p[j])
					break;
			}
			if (j == m) return i;
		}

		if (i < n - m) {
			th = (d*(th - t[i] * k) + t[i + m]) % PRIME;

			// th가 음수일 경우
			if (th < 0) th = (th + PRIME);
		}
	}
	return n;
}

int main()
{
	char t[] = "abdkdkekakfssadfabcdabcefslkjfsalkf";
	char p[] = "abcdabcef";

	puts(t + KarpRabin(t, p));
	return 0;
}


