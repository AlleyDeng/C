#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/* �˳�����vc6.0�±�����������ȷ�ģ�
    ��vs2008�ϱ���ɹ��������л����stack overflow !
    �߰汾�ı�����Ĭ�Ϸ���ĵ�ջ�ռ�СһЩ��
    Ӧ�ÿ����ڱ�����������Ĭ�Ϸ����ջ�Ĵ�С��,
    ����������õĻ����Խ��ʺ�������١�
*/

//NUM����8ʱ, Ƶ���ĵݹ���û����ջ�ռ����
#define NUM 8  //8���ʺ�

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
        for(i=0; i<NUM; i++)  //��ʼ������
        {
                for(j=0; j<NUM; j++)
                {
                        chess[i][j] = '0';
                }
        }
        start = clock();
        SolveQueen(chess, 0, 0);   //��(0,0)��ʼ����
}

//NUM���ʺ����η��÷ŵ���0�е���NUM-1�е���Ӧλ��, ��j���ϵĻʺ����λ�õ�ȷ�������α�����0�е���NUM-1��, ����i�а�ȫ, �ʺ�λ��chess(i,j)=1
void SolveQueen(char (*chess)[NUM], int i, int j)
{
        while(i<NUM)
        {
                if( !NotSafety(chess, i, j) )  //��ǰλ�ð�ȫ
                {
                        *(*(chess+i)+j) = '1';  //������Ԫ��chess(i,j)=1
                        if(j==NUM-1)  //�ҵ�һ�ַ���
                        {
                                ShowQueen(chess);  //��λ�ô�ӡ����
                                chess[i][j] = '0'; //��0, ׼��������һ��
                        }
                        else
                        {
                                SolveQueen(chess, 0, j+1);  //������һ��
                        }
                }
                i++;  //��ǰ�в���ȫ, �����ƶ�һ��
        }
        if(i==NUM)  //��ǰ�ж�����ȫ
        {
                MoveBack(chess, 0, j-1);  //��ǰ����һ��
        }
}

//�жϵ�ǰλ���Ƿ�ȫ, ������ȫ����1, ���򷵻�0
int NotSafety(char (*chess)[NUM], int i, int j)
{
        //�ж�ͬһ���Ƿ�ȫ
        int m, n;
        m = j-1;
        if(m>=0) //��
        {
                while( m>=0 && chess[i][m--]!='1' );
                if(chess[i][++m]=='1')
                {
                        return 1;
                }
        }

        //�ж����Խ����Ƿ�ȫ
        //���Ϸ�
        m = i-1;  //��
        n = j-1;  //��
        if(m>=0 && n>=0)
        {
                while(m>=0 && n>=0 && chess[m--][n--]!='1');
                if(chess[++m][++n]=='1')
                {
                        return 1;
                }
        }

        //�жϴζԽ����Ƿ�ȫ
        //���·�
        m = i+1;  //��
        n = j-1;  //��
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

//������ǰһ��, �����Ը���δ�������н�������
void MoveBack(char (*chess)[NUM], int i, int j)
{
        while(chess[i++][j]!='1');  //�ҵ�֮ǰ��������
        chess[--i][j] = '0';  //������Ч
        if(i==NUM-1 && j-1>=0)  //�����е������ж���Ч, ���������ǰһ��; j-1>=0 ��ʾ��ǰ��j=0 ʱ�Ͳ�������ǰ������, ��Ϊ������0-1=-1��������
        {
                MoveBack(chess, 0, j-1);
        }
        if(i==NUM-1 && j-1<0)  //�����ݵ�chess(NUM-1,0)�����нⷨ��ȫ����������, ��ֹ��������
        {
                finish = clock();
                printf("\n%d�ʺ�����Ľ⹲��%d��!\n",NUM, cnt);
                printf("\n��ʱ%ldms\n", finish-start);
                _getch();
                exit(0);
        }
        SolveQueen(chess, i+1, j);  //������һ��
}

void ShowQueen(char (*chess)[NUM])
{
        int i, j;
        printf("\n��%d�ַ��� :  ", ++cnt);
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
