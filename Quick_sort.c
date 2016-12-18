#include <stdio.h>

int *quick_sort(int *arr, int left, int right)
{
	if (left < right) {
		int i = left;
		int j = right;
		int pivot = arr[left];
		while (i < j) {
			while (arr[j] > pivot && i < j) {
				j --;
			}
			if (i < j) {
				arr[i ++] = arr[j];
			}
			while (arr[i] < pivot && i < j) {
				i ++;
			}
			if (i <= j) {
				arr[j] = arr[i];
			}
			arr[i] = pivot;
		}
		quick_sort(arr, left, i - 1);
		quick_sort(arr, i + 1, right);
	}

	return arr;
}

int main (void)
{
	int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

	quick_sort(arr, 0, 9);

	for (int i = 0; i < 10; i ++) {
		printf ("%d ", arr[i]);
	}
	printf ("\n");

	return 0;
}
