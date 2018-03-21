#include <stdio.h>
#include <stdlib.h>

int File_open_fp1(int ,char); //�}��Ū��-----�h�����@
int File_open_fp2(int ,char ); //�}��Ū��-----�h�����G
void Into_array(int ,int ); //�N�Ȧs�J�}�C 
int Add(int , int);  //�h���O�ۥ[ 
void Print();  //Printf�̫ᵲ�G  �s��c_poly.txt�ñN�̫ᵲ�G�s�J

int length_a = 0; //c_poly�̦h�i�H��h�� 
int length_b = 0; //b_poly�̦h�i�H��h�� 
int length_c = 0;  //c_poly�̦h�i�H��h�� 
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
   
   printf("�п�J�ɦW: ");
   scanf("%s",filename_1);
   
   
   if((fp1 = fopen(filename_1,"r")) == NULL)
   {
      printf("�}�ɥ���....\n");
      system("pause");
      exit(0);
   }
    
   while(1)   //�p���ɮפ@�� �@���X�ӼƦr  ���F����}�C�j�p   
   {
      ch = getc(fp1);
      if(ch == EOF) break;
      if(ch == ' ')
      {
         x = x + 1;
      }
   }
   printf("\n �@�� %d �ӼƦr\n\n",x+1);
   x = x+1;
   return x;
}

int File_open_fp2(int y , char filename2)
{
   FILE *fp2;
   char ch;
   
   printf("�п�J�ɦW: ");
   scanf("%s",filename_2);
   
   if((fp2 = fopen(filename_2,"r")) == NULL)
   {
      printf("�}�ɥ���....\n");
      system("pause");
      exit(0);
   }
    
   while(1)   //�p���ɮפ@�� �@���X�ӼƦr  ���F����}�C�j�p
   {
      ch = getc(fp2);
      if(ch == EOF) break;
      if(ch == ' ')
      {
         y = y + 1;
      }
   }
   printf("\n �@�� %d �ӼƦr\n\n",y+1);
   y = y+1;
   return y;
}

void Into_array(int j , int k)
{
   FILE *fp1;
   FILE *fp2;
   int i=0,num=0,temp=0;  
   int a=0,b=0;  //a���Y�ƼȦs  b�����ƼȦs 
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
   
   /* �C�X�Ĥ@�ӡB�ĤG�Ӱ}�C */ 
   printf("a �}�C\n");
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
   
   printf("b �}�C\n");
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
       if(Equation3[0][k] != 0)  //�p�G�ۥ[���P �h���L�X 
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
   /* �C�X�ĤT�Ӱ}�C */ 
   int g , h;
   printf("answer �}�C\n");
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
    if(Equation3[0][i] < 0)  //���P�_���t 
    {
      if(i==length_c)   //�p�G�O�t  �P�_�O�_���̫�@�ӱ`�� 
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
		  if(Equation3[1][i] == 1)   //�p�G�O�t �P�_�O�_��X���@���� 
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
      if(Equation3[0][i] == 0 && Equation3[1][i] == 0)   //�P�_�̫᪺�}�C������P�Y�ƬO�_��0 
      {
      	break;	
      }     
      if(i==0)  //�p�G�O��  �P�_�O�_���h�����Ĥ@�ӼƦr 
      {
        printf("%dX^%d", Equation3[0][i] , Equation3[1][i]);
        fprintf(fp3,"%dX^%d",Equation3[0][i],Equation3[1][i]);
      }
      else
      {
        if(Equation3[1][i] == 0)  //�p�G�O��  �P�_�O�_���̫�@�ӱ`�� 
        {
       	  printf("+%d",Equation3[0][i]);
          fprintf(fp3,"+%d",Equation3[0][i]);
		}
		else
		{
 	      if(Equation3[1][i] == 1)
		  {
		    printf("+%dX", Equation3[0][i]);  //�p�G�O�� �P�_�O�_��X���@����  
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
