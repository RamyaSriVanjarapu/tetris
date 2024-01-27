#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define height 20
#define width 10
int board[height][width];
typedef struct
{
   int x,y;
   int shape[4][4];

}block;
block block1;
block block2;
void initialize()
{
   int board[height][width]={0};
}
void printboard()
{
   
   for (int i=0;i<height;i++)
   {
      for(int j=0;j<width;j++)
      {
         if (board[i][j]==0)
         printf(". ");
         else
         printf("# ");
      }
      printf("\n");
   }
   return;
}
void printblock(block type)
{
   for(int i=0;i<4;i++)
   {
      for(int j=0;j<4;j++)
      {
        if(type.shape[i][j]!=0)
        board[i+type.x][j+type.y]=1;
      }
   }
   return;
}
void clearblock(block type)
{
   for(int i=0;i<4;i++)
   {
      for(int j=0;j<4;j++)
      {
        if(type.shape[i][j]!=0)
        board[i+type.x][j+type.y]=0;
      }
   }
}
block newblock()
{
   block type;
   int shapes[8][4][4]={{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
                         {{1,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}},
                         {{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
                         {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                         {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
                         {{1,1,0,0},{0,1,0,0},{0,0,0,0},{0,0,0,0}},
                         {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                         {{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},};
   int random=rand()%7;
   for(int i=0;i<height;i++)
   {
      for(int j=0;j<width;j++)
      {
       type.shape[i][j]=shapes[random][4][4];
      }
   }
   type.x=0;
   type.y=width/2-2;
   return type;
}
int check(block type)
{
  for(int i=0;i<4;i++)
  {
   for(int j=0;j<4;j++)
   {
      if(type.shape[i][j]!=0&&board[i+type.x][j+type.y]!=0||i+type.x>=height||i+type.y<=0||i+type.y>=width)
      return 1;
      else
      return 0;
   }
  }
}
block blockin()
{
   block2=newblock();
   block1=block2;
   return block1;
   
}
void blockmove()
{
   initialize();
   srand(time(0));
   blockin();
   while(1)
   {
   printboard();
   printblock(blockin());
   printboard();
   char direction;
   scanf("%c",&direction);
   switch(direction)
   {
      case 'd':
      if(!check(block1))
      clearblock(block1);
      --block1.y;
      printblock(block1);
      break;
      case 'f':
      if(!check(block1))
      clearblock(block1);
      ++block1.y;
      printblock(block1);
      break;
      case 'c':
      if(!check(block1))
      {
      clearblock(block1);
      block1.x++;
      printblock(block1);
      }
      break;
      case 'r':
      int temp;
      if(!check(block1))
      {
         
         clearblock(block1);
      temp=block1.x;
      block1.y=3-temp;
      block1.x=block1.y;
      printblock(block1);
      }
      break;
   
   }
   }
}
int main()
{
   blockmove();
   return 0;  
}

