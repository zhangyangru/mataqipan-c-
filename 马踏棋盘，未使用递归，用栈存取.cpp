#include <stdio.h>
#include <stdlib.h>
#define X 8
#define Y 8
#define MAXSIZE X*Y 

//λ�õ����� 
typedef struct
{
	int x;//������(0~7) 
	int y;//������(0~7)
	int d;//�Ѿ�̽�����ķ���(����ֵΪ3,��ʾ�Ѿ�̽������1,2,3����������) 
}spot;



//ջ�ṹ��,�߹��ĵ�Ҫ���浽ջ�� 
typedef struct
{
	int top;
	spot point[MAXSIZE];//��������һ����8*8����64���񣬿���һ�����飬��64��Ԫ�أ�ÿ��Ԫ�ض���һ��spot���͵Ľṹ�� 
}SeqStack;

 
 
//��ʼ��ջ 
SeqStack *Init_SeqStack()
{
	SeqStack *s;
	s=(SeqStack *)malloc(sizeof(SeqStack));
	s->top=-1;
	return s; 
 } 
 


//��ջ 
int Push_SeqStack(SeqStack *s,spot cur)//����һ��λ�õ����͵Ľṹ�� 
{
	if(s->top==MAXSIZE-1)
	     return 0;//ջ��,���̵�ÿһ��λ�ö��Ѿ����������� 
	else
	{
		s->top++;
		s->point[s->top].x = cur->x;//����ǰ���x��y��ջ 
		s->point[s->top].y = cur->y;
        return 1;	    
    }
} 



//��ջ 
int Pop_SeqStack(SeqStack *s)
{
	if(s->top==-1)
	return 0;//ջΪ�գ�û��Ԫ�ؿɳ� 
	else
	{
		s->top--;
		return 1; //��ջ�ɹ� 
    }
} 


//�ж��ҵ��ĸõ�λ���Ƿ���� 
int  Feasible(int x,int y)
 {
 	if((x>=0)&&(x<X)&&(y>=0)&&(y<Y)&&board[x][y]==0)
    return 1;//λ�õ���з���1 
    else
    return 0;//�����з���0
 }


//����һ�����е㣬���մ�1~8�ķ����ң��ҵ���һ�����е㣬���ض�Ӧ��spot���͵Ľṹ�壬������µĵ㣬��ô��1�ŷ���ʼ�ң���ʱcur.d��0��������Ǿɵ�
//�㣬��ô��cur.d+1�ķ���ʼ�ҡ� 
int Next Direction(spot cur,spot *temp)
{
	int i,x,y;
	for(i=cur.d+1;i<=8;i++)//һ���˸����� 
	{
		temp->x=cur.x+dierction[0][i];
		temp->y=cur.y+direction[1][i];
		temp->d=i;
		if(Feasible(x,y))//λ�õ����ִ�� 
		{
	     	return i;//���ؿ����ƶ��ķ���i 
	    }
	}
	return 0;//û���ҵ���һ���㷵��0 
} 
    

 
int main()
{
	int x,y;
	int direction[2][9]={{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}}//���а���,����ӵ�ǰλ���ƶ�����һ������λ�ú���������Ҫ�ֱ��ƶ��ľ��� 
	SeqStack *s;//ָ��ջ�ṹ���ָ�� 
	spot cur,next;//cur:��ǰ��λ�õ㣬next:��һ��λ�õ� 
	spot *temp;
	int board[8][8]={0};//����һ��8��8������,�����������ʼ��Ϊ0
	int step;//��ʾ��ǰ�Ѿ���ɵĲ��� 
	printf("��������ʼ��λ������(0~7)");
	scanf("%d%d",&x,&y);//������ʼ��λ���±� (�Զ���) 
    board[x][y]=1;//����1��ʾ�õ��߹��ˣ����û���߹�����Ϊ0 
    cur.x=x;
    cur.y=y;
    s=Init_SeqStack();//��ʼ��ջ 
    for(step=1;step<64;step++) 
    {
         if(Next Direction(cur,&temp)==0)//���뵱ǰ�ĵ㣬ȥѰ����һ�����λ��,����ֵ��0��ʾû���ҵ���һ���� 
         { 
	         step--;
	         Pop_SeqStack(s);//��ջ��ǰԪ�� 
//	         cur.x = temp.x;
//	         cur.y = temp.y;
//	         cur.d = temp.d;
	         board[cur.x][cur.y]=0;
         } 
         
         else//���ص�ֵ��1,�ҵ�����һ���� 
         { 
            Push_SeqStack(s,cur);//�ѵ�ǰ�㱣�浽ջ�� 
         }
          cur = temp;//��������д�� 
      }


 
 
