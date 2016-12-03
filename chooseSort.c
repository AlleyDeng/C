#include <stdio.h>

int *chooseSort(int *arr, int n)
{
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[k] < arr[j]) {
				k = j;
			}
		}
		if (k != i) {
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
	return arr;
}

int main (void)
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p = arr;	

	p = chooseSort(arr, 10);

	for (int i = 0; i < 10; i ++) {
		printf ("%d ", p[i]);
	}

	return 0;
}
