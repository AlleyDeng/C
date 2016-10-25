#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/* 此程序在vc6.0下编译运行是正确的，
    在vs2008上编译成功，但运行会出现stack overflow !
    高版本的编译器默认分配的的栈空间小一些，
    应该可以在编译器里设置默认分配的栈的大小的,
    如果不能设置的话可以将皇后个数减少。
*/

//NUM大于8时, 频繁的递归调用会造成栈空间溢出
#define NUM 8  //8个皇后

void SolveQueen(char (*)[NUM], int, int);
int NotSafety(char (*)[NUM], int, int);
void MoveBack(char (*)[NUM], int, int);
void ShowQueen(char (*)[NUM]);

int cnt = 0;
clock_t start, finish;

int main()
{
        char chess[NUM][NUM];
        int i, j;
        for(i=0; i<NUM; i++)  //初始化棋盘
        {
                for(j=0; j<NUM; j++)
                {
                        chess[i][j] = '0';
                }
        }
        start = clock();
        SolveQueen(chess, 0, 0);   //从(0,0)开始搜索
}

//NUM个皇后依次放置放到第0列到第NUM-1列的相应位置, 第j列上的皇后具体位置的确定需依次遍历第0行到第NUM-1行, 若第i行安全, 皇后位置chess(i,j)=1
void SolveQueen(char (*chess)[NUM], int i, int j)
{
        while(i<NUM)
        {
                if( !NotSafety(chess, i, j) )  //当前位置安全
                {
                        *(*(chess+i)+j) = '1';  //置棋盘元素chess(i,j)=1
                        if(j==NUM-1)  //找到一种方案
                        {
                                ShowQueen(chess);  //将位置打印出来
                                chess[i][j] = '0'; //清0, 准备搜索下一行
                        }
                        else
                        {
                                SolveQueen(chess, 0, j+1);  //搜索下一列
                        }
                }
                i++;  //当前行不安全, 向下移动一行
        }
        if(i==NUM)  //当前列都不安全
        {
                MoveBack(chess, 0, j-1);  //向前回溯一列
        }
}

//判断当前位置是否安全, 若不安全返回1, 否则返回0
int NotSafety(char (*chess)[NUM], int i, int j)
{
        //判断同一行是否安全
        int m, n;
        m = j-1;
        if(m>=0) //←
        {
                while( m>=0 && chess[i][m--]!='1' );
                if(chess[i][++m]=='1')
                {
                        return 1;
                }
        }

        //判断主对角线是否安全
        //左上方
        m = i-1;  //↑
        n = j-1;  //←
        if(m>=0 && n>=0)
        {
                while(m>=0 && n>=0 && chess[m--][n--]!='1');
                if(chess[++m][++n]=='1')
                {
                        return 1;
                }
        }

        //判断次对角线是否安全
        //左下方
        m = i+1;  //↓
        n = j-1;  //←
        if(m<NUM && n>=0)
        {
                while(m<NUM && n>=0 && chess[m++][n--]!='1');
                if(chess[--m][++n]=='1')
                {
                        return 1;
                }
        }
        return 0;
}

//回溯至前一列, 继续对该列未搜索的行进行搜索
void MoveBack(char (*chess)[NUM], int i, int j)
{
        while(chess[i++][j]!='1');  //找到之前搜索的行
        chess[--i][j] = '0';  //该行无效
        if(i==NUM-1 && j-1>=0)  //若该列的所有行都无效, 则继续回溯前一列; j-1>=0 表示当前列j=0 时就不能再向前回溯了, 因为回溯至0-1=-1列无意义
        {
                MoveBack(chess, 0, j-1);
        }
        if(i==NUM-1 && j-1<0)  //若回溯到chess(NUM-1,0)则所有解法已全部遍历结束, 终止程序运行
        {
                finish = clock();
                printf("\n%d皇后问题的解共有%d个!\n",NUM, cnt);
                printf("\n耗时%ldms\n", finish-start);
                _getch();
                exit(0);
        }
        SolveQueen(chess, i+1, j);  //搜索下一行
}

void ShowQueen(char (*chess)[NUM])
{
        int i, j;
        printf("\n第%d种方案 :  ", ++cnt);
        putchar('\n');
        for(i=0; i<NUM; i++)
        {
                for(j=0; j<NUM; j++)
                {
                        printf("%c ", *(*(chess+i)+j));
                }
                putchar('\n');
        }
}
