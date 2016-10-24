#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Status int
#define TRUE 1
#define FALSE 0

void BubbleSort(int *r, int length)
{
	int i, j;
	Status flag = TRUE;	/* 初始为false */
	for (i = 0; i < length - 1 && flag; i++) {
		flag = FALSE;
		for (j = length - 1; j >= i; j --) {
			if (r[j] > r[j+1]) {
				int temp = r[j];
				r[j] = r[j + 1];
				r[j + 1]  = temp;
				flag = TRUE;
			}
		}
	}
}

int main (void)
{
	int arr[10] = {10 , 3, 5, 7, 2, 9, 1, 6, 4, 8};

	BubbleSort(arr, 10);

	for (int i = 0; i < 10; i++) {
		printf ("%d\t", arr[i]);
	}

	return 0;
}

