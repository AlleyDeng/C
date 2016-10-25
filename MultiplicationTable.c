#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void gotoxy(int x, int y)
{
	printf ("%c[%d;%df", 0x1B, y, x);
}

int main (void)
{
	int i, j, x, y;
	system("clear");
	printf ("\n\n * * * Multiplication table * * * \n\n");
	x =  9;
	y = 5;
	for (i = 1; i <= 9; i ++) {
		gotoxy(x, y);
		printf ("%2d ", i);
		x += 3;
	}
	x = 7;
	y = 6;
	for (i = 1; i <= 9; i++) {
		gotoxy(x, y);
		printf ("%2d ", i);
		y ++;
	}
	x = 9;
	y = 6;
	for (i = 1; i <= 9; i ++) {
		for (j = 1; j <= 9; j++) {
			gotoxy(x, y);
			printf ("%2d ", i * j);
			y ++;
		}
		y -= 9;
		x += 3;
	}
	printf ("\n\n");
	return 0;
}
