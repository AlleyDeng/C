#include <stdio.h>

int AddTwoNum(int num1, int num2)
{
	if (0 == num1) {
		return num2;
	}
	if (0 == num2) {
		return num1;
	}

	int temp1 = num1 ^ num2;
	int temp2 = num1 & num2;

	return AddTwoNum(temp1, temp2);
}

int main (void)
{
	int num1, num2;
	scanf("%d%d", &num1, &num2);
	printf("%d+%d=%d\n",num1, num2, AddTwoNum(num1, num2));

	return 0;
}
