/*
 *基姆拉尔森计算公式
 *W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
 *注意：
 *     在公式中有个与其他公式不同的地方：把一月和二月看成是上一年的十三月和十四月
 */
#include <stdio.h>
void CaculateWeekDay(int y,int m, int d)
{
	if(m==1||m==2) {
		m+=12;
		y--;
	}
	int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	switch(iWeek)
	{
		case 0: printf("Monday\n"); break;
		case 1: printf("Tuesday\n"); break;
		case 2: printf("Wednesday\n"); break;
		case 3: printf("Thursday\n"); break;
		case 4: printf("Friday\n"); break;
		case 5: printf("Saturday\n"); break;
		case 6: printf("Sunday\n"); break;
	}
} 
int main(void)
{
	int year=0,month=0,day=0;
	printf("Pelase enter the date：(1900,1,1)\n");
	char temp = '1';
	while (temp != '0')
	{
		scanf("%d,%d,%d",&year,&month,&day);
		scanf("%c",&temp);
		CaculateWeekDay(year,month,day);
		printf("Input 0 to stop,else to continue:");
		scanf("%c",&temp);
	}

	return 0;
}
