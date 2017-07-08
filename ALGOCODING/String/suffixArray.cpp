/*
 * ���̾� �迭
 *
 *  Author: JongYun, Jung
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
#define MAX_N 100010                         // second approach: O(n log n)
char T[MAX_N];                   // the input string, up to 100K characters
int n;                                        // the length of input string
int RA[MAX_N], tempRA[MAX_N];        // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N];    // suffix array and temporary suffix array
int c[MAX_N];                                    // for counting/radix sort

char P[MAX_N];                  // the pattern string (for string matching)
int m;                                      // the length of pattern string

int Rank[MAX_N];                      // for computing longest common prefix
int Height[MAX_N];
int LCP[MAX_N];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]

// and current suffix T+SA[i]
void countingSort(int k) {                                          // O(n)
	int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
	memset(c, 0, sizeof c);                          // clear frequency table
	for (i = 0; i < n; i++)       // count the frequency of each integer rank
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)                     // update the suffix array SA
		SA[i] = tempSA[i];
}

void constructSA() {         // this version can go up to 100000 characters
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
	for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
	for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
		countingSort(k);  // actually radix sort: sort based on the second item
		countingSort(0);          // then (stable) sort based on the first item
		tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
		for (i = 1; i < n; i++)                    // compare adjacent suffixes
			tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
			(RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)                     // update the rank array RA
			RA[i] = tempRA[i];
		if (RA[SA[n - 1]] == n - 1) break;               // nice optimization trick
	}
}

void computeLCP() {
	int i, h;
	Rank[SA[0]] = -1;                                         // default value

	for (i = 1; i < n; i++)                            // compute Rank in O(n)
		Rank[SA[i]] = SA[i - 1];    // remember which suffix is behind this suffix

	for (i = h = 0; i < n; i++) {             // compute Permuted LCP in O(n)
		if (Rank[i] == -1) { Height[i] = 0; continue; }// special case
		while (T[i + h] == T[Rank[i] + h]) h++;        // L increased max n times

		Height[i] = h;
		if(h > 0) h = h - 1;
	}
	for (i = 0; i < n; i++)       // compute LCP in O(n)
		LCP[i] = Height[SA[i]];   // put the permuted LCP to the correct position
}


int main() {
	//printf("Enter a string T below, we will compute its Suffix Array:\n");
	strcpy(T, "GATAGACA");
	n = (int)strlen(T);
	T[n++] = '$';
	// if '\n' is read, uncomment the next line
	//T[n-1] = '$'; T[n] = 0;

	printf("The Suffix Array of string T = '%s' is shown below (O(n^2 log n) version):\n", T);
	printf("i\tSA[i]\tSuffix\n");

	constructSA();                                              // O(n log n)
	computeLCP();                                                     // O(n)

	printf("\nThe Suffix Array of string T = '%s' is shown below (O(n log n) version):\n", T);
	printf("i\tSA[i]\tSuffix\n");
	for (int i = 0; i < n; i++) printf("%2d\t%2d\t%2d\t%s\n", i, SA[i], LCP[i], T + SA[i]);



	return 0;
}


