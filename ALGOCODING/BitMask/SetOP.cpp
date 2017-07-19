/*
 * 집합 연산
 *
 *  Created on: 2017. 7. 12.
 *      Author: JongYun
 */

#include <stdio.h>
const int SETSIZE = 8;
void printSet(int set, char data[])
{
    for (int i = 0; i < SETSIZE; i++)
        if (set & (1 << i))
            printf("%c ", data[i]);

    printf("\n");
}

int main()
{
    int A = 0x2D, B = 0x65;
    char data[] = "ABCDEFGH";

    printSet(A, data);  //
    printSet(B, data);

    printf("합집합> "); printSet(A | B, data);
    printf("교집합> "); printSet(A & B, data);
    printf(" ~A > "); printSet(~A, data);
    printf("A-B > "); printSet(A & ~B, data);
    return 0;
}


