#include <stdio.h>

void insertSort(int *arr, int n)  
{  
	int i,j,key;  
	for(j = 1; j < n; j ++) {  
		key = arr[j];  
		i = j - 1;   
		while(i >= 0 && arr[i] > key) {  
			arr[i+1] = arr[i];  
			i --;  
		}  
		arr[i+1] = key;  
	}  
}

int main (void)
{
	int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	insertSort(arr, 10);

	for (int i = 0; i < 10; i++) {
		printf ("%d ", arr[i]);
	}
}
