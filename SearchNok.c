#include <stdio.h>

int Search_No.k(int *arr, int len, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return arr[n - 1];
}

int main (void)
{
	int arr[10] = {1, 3, 5, 10, 7, 2, 9, 4, 8, 6};

	 printf ("%d\n", search(arr, 10, 5));

	return 0;
}
