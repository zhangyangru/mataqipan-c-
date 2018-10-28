#include <stdio.h>
#include <stdlib.h>
#define X 8
#define Y 8
#define MAXSIZE X*Y 

//位置点类型 
typedef struct
{
	int x;//横坐标(0~7) 
	int y;//纵坐标(0~7)
	int d;//已经探索过的方向(若其值为3,表示已经探索过了1,2,3这三个方向) 
}spot;



//栈结构体,走过的点要保存到栈里 
typedef struct
{
	int top;
	spot point[MAXSIZE];//假如棋盘一共有8*8等于64个格，开辟一个数组，有64个元素，每个元素都是一个spot类型的结构体 
}SeqStack;

 
 
//初始化栈 
SeqStack *Init_SeqStack()
{
	SeqStack *s;
	s=(SeqStack *)malloc(sizeof(SeqStack));
	s->top=-1;
	return s; 
 } 
 


//入栈 
int Push_SeqStack(SeqStack *s,spot cur)//传入一个位置点类型的结构体 
{
	if(s->top==MAXSIZE-1)
	     return 0;//栈满,棋盘的每一个位置都已经填入了坐标 
	else
	{
		s->top++;
		s->point[s->top].x = cur->x;//将当前点的x和y入栈 
		s->point[s->top].y = cur->y;
        return 1;	    
    }
} 



//出栈 
int Pop_SeqStack(SeqStack *s)
{
	if(s->top==-1)
	return 0;//栈为空，没有元素可出 
	else
	{
		s->top--;
		return 1; //出栈成功 
    }
} 


//判断找到的该点位置是否可行 
int  Feasible(int x,int y)
 {
 	if((x>=0)&&(x<X)&&(y>=0)&&(y<Y)&&board[x][y]==0)
    return 1;//位置点可行返回1 
    else
    return 0;//不可行返回0
 }


//找下一个可行点，按照从1~8的方向找，找到第一个可行点，返回对应的spot类型的结构体，如果是新的点，那么从1号方向开始找（此时cur.d是0），如果是旧的
//点，那么从cur.d+1的方向开始找。 
int Next Direction(spot cur,spot *temp)
{
	int i,x,y;
	for(i=cur.d+1;i<=8;i++)//一共八个方向 
	{
		temp->x=cur.x+dierction[0][i];
		temp->y=cur.y+direction[1][i];
		temp->d=i;
		if(Feasible(x,y))//位置点可行执行 
		{
	     	return i;//返回可以移动的方向i 
	    }
	}
	return 0;//没有找到下一个点返回0 
} 
    

 
int main()
{
	int x,y;
	int direction[2][9]={{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}}//两行八列,代表从当前位置移动到下一个方向位置横纵坐标需要分别移动的距离 
	SeqStack *s;//指向栈结构体的指针 
	spot cur,next;//cur:当前的位置点，next:下一个位置点 
	spot *temp;
	int board[8][8]={0};//定义一个8乘8的棋盘,给棋盘数组初始化为0
	int step;//表示当前已经完成的步数 
	printf("请输入起始的位置坐标(0~7)");
	scanf("%d%d",&x,&y);//输入起始的位置下标 (自定义) 
    board[x][y]=1;//等于1表示该点走过了，如果没有走过，则为0 
    cur.x=x;
    cur.y=y;
    s=Init_SeqStack();//初始化栈 
    for(step=1;step<64;step++) 
    {
         if(Next Direction(cur,&temp)==0)//传入当前的点，去寻找下一个点的位置,返回值是0表示没有找到下一个点 
         { 
	         step--;
	         Pop_SeqStack(s);//出栈当前元素 
//	         cur.x = temp.x;
//	         cur.y = temp.y;
//	         cur.d = temp.d;
	         board[cur.x][cur.y]=0;
         } 
         
         else//返回的值是1,找到了下一个点 
         { 
            Push_SeqStack(s,cur);//把当前点保存到栈里 
         }
          cur = temp;//可以这样写吗？ 
      }


 
 
