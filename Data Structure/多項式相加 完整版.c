#include <stdio.h>
#include <stdlib.h>

int File_open_fp1(int ,char); //開檔讀檔-----多項式一
int File_open_fp2(int ,char ); //開檔讀檔-----多項式二
void Into_array(int ,int ); //將值存入陣列 
int Add(int , int);  //多項是相加 
void Print();  //Printf最後結果  新建c_poly.txt並將最後結果存入

int length_a = 0; //c_poly最多可以到多少 
int length_b = 0; //b_poly最多可以到多少 
int length_c = 0;  //c_poly最多可以到多少 
int Equation1[2][40]={0};
int Equation2[2][40]={0};
int Equation3[2][40]={0};
char filename_1[10]={0} , filename_2[10]={0};

int main(void)
{   
   length_a = File_open_fp1(length_a,filename_1);
   length_b = File_open_fp2(length_b,filename_2);
   Into_array(length_a,length_b);
   length_c = Add(length_a,length_b);
   Print();
   
   printf("\n\n");
   system("pause");
   return 0; 
}

int File_open_fp1(int x , char filename1)
{
   FILE *fp1;
   char ch;
   
   printf("請輸入檔名: ");
   scanf("%s",filename_1);
   
   
   if((fp1 = fopen(filename_1,"r")) == NULL)
   {
      printf("開檔失敗....\n");
      system("pause");
      exit(0);
   }
    
   while(1)   //計算檔案一中 共有幾個數字  為了限制陣列大小   
   {
      ch = getc(fp1);
      if(ch == EOF) break;
      if(ch == ' ')
      {
         x = x + 1;
      }
   }
   printf("\n 共有 %d 個數字\n\n",x+1);
   x = x+1;
   return x;
}

int File_open_fp2(int y , char filename2)
{
   FILE *fp2;
   char ch;
   
   printf("請輸入檔名: ");
   scanf("%s",filename_2);
   
   if((fp2 = fopen(filename_2,"r")) == NULL)
   {
      printf("開檔失敗....\n");
      system("pause");
      exit(0);
   }
    
   while(1)   //計算檔案一中 共有幾個數字  為了限制陣列大小
   {
      ch = getc(fp2);
      if(ch == EOF) break;
      if(ch == ' ')
      {
         y = y + 1;
      }
   }
   printf("\n 共有 %d 個數字\n\n",y+1);
   y = y+1;
   return y;
}

void Into_array(int j , int k)
{
   FILE *fp1;
   FILE *fp2;
   int i=0,num=0,temp=0;  
   int a=0,b=0;  //a為係數暫存  b為指數暫存 
   fp1 = fopen(filename_1,"r");
   fp2 = fopen(filename_2,"r");
   
   
   while(i<j)
   {
      fscanf(fp1, "%d", &num);
      if(temp == 0)
      {
        Equation1[0][a] = num;
        temp = 1;
        a = a + 1;
      }
      else
      if(temp == 1)
      {
        Equation1[1][b] = num;
        temp = 0;
        b = b + 1;
      }
      i = i + 1;
   }
   
   i = 0;
   temp = 0;
   a = 0;
   b = 0;
   
   while(i<k)
   {
      fscanf(fp2, "%d", &num);
      if(temp == 0)
      {
        Equation2[0][a] = num;
        temp = 1;
        a = a + 1;
      }
      else
      if(temp == 1)
      {
        Equation2[1][b] = num;
        temp = 0;
        b = b + 1;
      }
      i = i + 1;
   }
   
   fclose(fp1);  
   fclose(fp2); 
   
   /* 列出第一個、第二個陣列 */ 
   printf("a 陣列\n");
   int g , h;
   for(g=0;g<2;g++)
   {
      for(h=0;h<j/2;h++)
      {
      	 printf("%3d ", Equation1[g][h]);
	  }
	  printf("\n");
   }
   printf("\n\n");
   
   printf("b 陣列\n");
   for(g=0;g<2;g++)
   {
      for(h=0;h<k/2;h++)
      {
      	 printf("%3d ", Equation2[g][h]);
	  }
	  printf("\n");
   }
}

int Add(int j ,int k)
{
   int n , i = 0;
   int z=0;
   n=j+k;
   i = 0; j = 0; k = 0;
   
   while(z<n)
   {
     if(Equation1[1][i] == Equation2[1][j])
     {
       Equation3[0][k] = Equation1[0][i] + Equation2[0][j];
       Equation3[1][k] = Equation1[1][i];
       i++;
       j++;
       z++;
       if(Equation3[0][k] != 0)  //如果相加後抵銷 則不印出 
       {
         k++;
       }
     }
     else
     {
       if(Equation1[1][i] > Equation2[1][j])
       {
          Equation3[0][k] = Equation1[0][i];
          Equation3[1][k] = Equation1[1][i];
          i++;
          k++;
          z++;
       }
       else
       {
          Equation3[0][k] = Equation2[0][j];
          Equation3[1][k] = Equation2[1][j];
          j++;
          k++;
          z++;
       }
     }
   }
   
   printf("\n\n");
   /* 列出第三個陣列 */ 
   int g , h;
   printf("answer 陣列\n");
   for(g=0;g<2;g++)
   {
      for(h=0;h<k;h++)
      {
      	 printf("%3d ", Equation3[g][h]);
	  }
	  printf("\n");
   }
   printf("\n\n");  
   return n;
}

void Print()
{
  FILE *fp3;
  fp3 = fopen("c", "w");
  int i = 0;
  for(i=0;i<length_c;i++)
  {
    if(Equation3[0][i] < 0)  //先判斷正負 
    {
      if(i==length_c)   //如果是負  判斷是否為最後一個常數 
      {
        printf("%d",Equation3[0][i]);
        fprintf(fp3,"%d",Equation3[0][i]);
      }
      else
      {
        if(Equation3[1][i] == 0)
        {
          printf("%d",Equation3[0][i]);
          fprintf(fp3,"%d",Equation3[0][i]);
  	    }
		else
		{
		  if(Equation3[1][i] == 1)   //如果是負 判斷是否為X的一次方 
		  {
		    printf("%dX", Equation3[0][i]);
		    fprintf(fp3,"%dX",Equation3[0][i]);
		  }
		  else
		  {
   	        printf("%dX^%d", Equation3[0][i] , Equation3[1][i]);
   	        fprintf(fp3,"%dX^%d",Equation3[0][i],Equation3[1][i]);
   	      }
   	    }
      }
    }
    else
    {
      if(Equation3[0][i] == 0 && Equation3[1][i] == 0)   //判斷最後的陣列中次方與係數是否為0 
      {
      	break;	
      }     
      if(i==0)  //如果是正  判斷是否為多項式第一個數字 
      {
        printf("%dX^%d", Equation3[0][i] , Equation3[1][i]);
        fprintf(fp3,"%dX^%d",Equation3[0][i],Equation3[1][i]);
      }
      else
      {
        if(Equation3[1][i] == 0)  //如果是正  判斷是否為最後一個常數 
        {
       	  printf("+%d",Equation3[0][i]);
          fprintf(fp3,"+%d",Equation3[0][i]);
		}
		else
		{
 	      if(Equation3[1][i] == 1)
		  {
		    printf("+%dX", Equation3[0][i]);  //如果是正 判斷是否為X的一次方  
		   	fprintf(fp3,"+%dX",Equation3[0][i]);
		  }
		  else
	      {
   	        printf("+%dX^%d", Equation3[0][i] , Equation3[1][i]);
   	        fprintf(fp3,"+%dX^%d",Equation3[0][i],Equation3[1][i]);
   	      }
		}
      }
    }
  }
  fclose(fp3);
}
