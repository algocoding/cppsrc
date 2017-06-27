/*
 * 2darr.cpp
 *
 *  Created on: 2017. 6. 27.
 *      Author: JongYun
 */

#include <stdio.h>
const int N = 5;
const int M = 4;
// ��켱
int arr1[][N] = {{1, 2, 3, 4, 5},
				 {6, 7, 8, 9, 10},
				 {11,12,13,14,15},
				 {16,17,18,19,20},
				 {21,22,23,24,25}};
// ���켱
int arr2[][N] = {{1,6,11,16,21}, {2,7,12,17,22}, {3,8,13,18,23}, {4,9,14,19,24},{5,10,15,20,25}};
// �������
int arr3[][N] = {{1,2,3,4,5}, {10,9,8,7,6}, {11,12,13,14,15}, {20,19,18,17,16},{21,22,23,24,25}};
// �밢
int arr4[M][N] = {{1,3,6,10,14},
				{2,5,9,13,17},
				{4,8,12,16,19},
				{7,11,15,18,20}};

int arr5[M][N] = {{1,2,4,7,11},
				{3,5,8,12,15},
				{6,9,13,16,18},
				{10,14,17,19,20}};

void RowFirstSearch(int arr[][N])
{
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%2d ", arr[i][j]);
		}
	}
	printf("\n");
}
void ColFirstSearch(int arr[][N])
{
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%2d ", arr[j][i]);
		}
	}
	printf("\n");
}
void zigzagSearch(int arr[][N])
{
	for(int i = 0; i < N; i++) {
		if(i & 1){	// Ȧ�� ��
			for(int j = N-1; j >= 0; j--)
				printf("%2d ", arr[i][j]);
		}else{		// ¦����
			for(int j = 0; j < N; j++)
				printf("%2d ", arr[i][j]);
		}
	}
	printf("\n");
}
int min(int a, int b){ return a < b? a: b;}
void diagonalSearch(int arr[M][N])
{
	for(int diag = 0; diag < M + N - 1; diag++)
	{	// �밢�� ���� = ��ũ�� + ��ũ�� - 1
		// x,y: �밢 ȭ��ǥ ���� ��ǥ
		int x = diag < N ? 0: (diag - N + 1);
		int y = diag < N ? diag: N - 1;

		while(x < M && y >= 0)
		{
			printf("%2d ", arr[x][y]);
			x++, y--;
		}
	}
}
void deltaSearch(int arr[][N])
{
	int dx[] = {0, 0, 1, -1};// ��, ��, ��, ��
	int dy[] = {1, -1, 0, 0};

	for(int x = 0; x < N; x++)
	for(int y = 0; y < N; y++){
		// ��ǥ ����
		for(int i = 0; i < 4; i++){
			int tx = x + dx[i];
			int ty = y + dy[i];

			// tx, ty�� ���� �۾� ����
		}
	}
}
void RectSearch(int arr[][N], int n)
{
	// x,y: ���� ��ǥ, n: Ž�� ���� ũ��
	for(int x = 0; x <= N - n; x++)
	for(int y = 0; y <= N - n; y++){

		for(int i = x; i < x + n; i++){
		for(int j = y; j < y + n; j++)
			//���ϴ� �۾� ����
			printf("%2d ", arr[i][j]);
		}
	}
}
int main()
{
	RowFirstSearch(arr1);
	ColFirstSearch(arr2);
	zigzagSearch(arr3);
	diagonalSearch(arr5);
	printf("--->\n");
	deltaSearch(arr1);
	RectSearch(arr1, 3);
	return 0;
}
//void diagonalSearch(int arr[M][N])
//{
//	for(int diag = 0; diag < M + N - 1; diag++)
//	{
//		int x = diag < M ? diag: M - 1;
//		int y = diag < M ? 0: (diag - M + 1);
//
//		while(x >= 0 && y < N)
//		{
//			printf("%2d ", arr[x][y]);
//			x--, y++;
//		}
//	}
//}
