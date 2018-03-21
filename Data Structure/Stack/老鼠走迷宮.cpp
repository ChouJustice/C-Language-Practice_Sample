#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void SetColor(int ,int );
void Input_maze();
void Print_maze();
void Print_mouse(int ,int );
void Clear_footprint(int ,int );
void Move(int ,int );
void Print(int ,int );

char maze[24][60];
char footprint[24][60];
int Mouse_HP = 500;
int success = 0;
int map_x , map_y;
int before_x , before_y;

int main(void)
{
	system("mode con cols=120 lines=40");
	Input_maze();
    Print_maze();
    Print_mouse(0,0);
    Print(0,30);
    printf("老鼠將於3秒後開始走迷宮...");
    Print(26,0);
    printf("\t Mouse HP %d",Mouse_HP);
    Sleep(3000);
    Move(0,0);
	
	system("pause");
	return 0;
}

void Input_maze()
{
  char filename[50];
  FILE *fp;
  int i , j;
  char ch[100];
  
  for(i=0;i<24;i++)
  {
    for(j=0;j<60;j++)
    {
       maze[i][j] = '\0';
    }
  }

  printf("請輸入地圖檔名 : ");
  gets(filename);
 
  fp = fopen(filename,"r");

  if (fp == NULL) 
  {
    printf("開檔失敗!\n");
    system("pause");
    exit(0);
  }
  else 
  {   
    i = 0;
    while(1) 
    {
      if(feof(fp)) break;
      fscanf(fp,"%s",ch);
      for(j=0;j<strlen(ch);j++)
	  {   
	     maze[i][j] = ch[j];
      }
      i++;
    }
  }
}

void Print_mouse(int x,int y)
{
   int loc_x , loc_y;
   loc_x = x+1;
   loc_y = y;  
   Sleep(100);
   Print(loc_x,loc_y*2);
   SetColor(6,0);
   printf("●");
   SetColor(7,0);
   
   if(success == 0)
  {
     Mouse_HP = Mouse_HP - 1;
     Print(26,0);
     printf("\t Mouse HP %d",Mouse_HP);
     if(Mouse_HP == 0)
     {
     	Print(26,0);
        printf("\t 老鼠GG了~~~");
        system("pause");
        exit(0);
	 }
  }
}

void Clear_footprint(int x,int y)
{
   int loc_x , loc_y;
   loc_x = x+1;
   loc_y = y;
   Sleep(100);
   Print(loc_x,loc_y*2);
   printf("　");
}

void Move(int x, int y)
{
  int i , new_x , new_y;
  int direction_x[] = {1,1,1,0,-1,-1,-1,0};
  int direction_y[] = {1,0,-1,-1,-1,0,1,1};  
 /* 
  if(success == 0)
  {
     Mouse_HP = Mouse_HP - 1;
     Print(26,0);
     printf("\t Mouse HP %d",Mouse_HP);
     if(Mouse_HP == 0)
     {
     	Print(26,0);
        printf("\t 老鼠GG了~~~");
        system("pause");
        exit(0);
	 }
  }
*/  
  if(maze[y][x] == '#')
  {
     success = 1;
     Print_mouse(y,x);
     Print(26,0);
     printf("\t Mouse HP %d  恭喜老鼠逃出迷宮!!! \n\n",Mouse_HP);
     system("pause");
     exit(0);
  }
  else if(maze[y][x] == '+') 
  {
     Mouse_HP = Mouse_HP + 50;
     Print(26,0);
     printf("\t Mouse HP %d",Mouse_HP);
  }
  else if(maze[y][x] == '-') 
  {
     Mouse_HP = Mouse_HP + 30;
     Print(26,0);
     printf("\t Mouse HP %d",Mouse_HP);
  }
  else if(maze[y][x] == '*') 
  {
     Mouse_HP = Mouse_HP + 80;
     Print(26,0);
     printf("\t Mouse HP %d",Mouse_HP);
  }
  else if(maze[y][x] == '$') 
  {
     Mouse_HP = Mouse_HP + 100;
     Print(26,0);
     printf("\t Mouse HP %d",Mouse_HP);
  }  
  Print_mouse(y,x);
  footprint[y][x] = '1';
  
  before_x = x;
  before_y = y;
  
  for(i=0;i<=7;i++)
  {
    new_x = x + direction_x[i];
    new_y = y + direction_y[i];
    if((maze[new_y][new_x] != '1') && (footprint[new_y][new_x] != '1')) 
    {
       Clear_footprint(y,x);
       Move(new_x,new_y);
      if(x != before_x)
      {
         Clear_footprint(before_y,before_x);
         Print_mouse(y,x);
      } 
      else if(y != before_y)
      {
      	 Clear_footprint(before_y,before_x);
         Print_mouse(y,x);
	  }
    }
  }
  Clear_footprint(y,x);
}

void Print_maze()
{
  int i,j;
  for(i=0;i<24;i++)
  {
    for(j=0;j<60;j++)
    {
      if(maze[i][j] == '0') 
	  {
	    printf("　");
      }
      else if(maze[i][j] == '1') 
      {
        SetColor(7,7);
        printf("▇");
      }
      else if(maze[i][j] == '+') 
      {
        SetColor(6,4);
        printf("＋");
      }
      else if(maze[i][j] == '-') 
      {
        SetColor(6,4);
        printf("－");
      }
      else if(maze[i][j] == '*') 
      {
        SetColor(6,4);
        printf("＊");
      }
      else if(maze[i][j] == '$') 
      {
        SetColor(6,4);
        printf("＄");
      }
      else if(maze[i][j] == '#') 
      {
        SetColor(6,4);
        printf("＃");
      }
      SetColor(7,0);
    }
  }
  printf("\n");
  
  for(i=0;i<24;i++)
  {
    for(j=0;j<60;j++)
    {
      footprint[i][j] = '\0';
    }
  }
}

void Print(int x,int y) 
{
	static HANDLE o = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD c = {y, x};
    SetConsoleCursorPosition (o, c);
}

void SetColor(int f=7,int b=0)
{
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}
