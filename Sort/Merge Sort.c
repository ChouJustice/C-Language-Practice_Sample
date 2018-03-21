#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int number[64] = {0};

void random_number();
void half_sort();
void find_biggest_numbers();
void find_lastnumber_swap();
void merge_sort();
void final_sort_out();

int main(void)
{
	random_number();
	half_sort();
	find_biggest_numbers();
	find_lastnumber_swap();
    merge_sort();
    final_sort_out();
    
	system("pause");
	return 0;
}

void random_number()
{
	printf("隨機產生64個不重複的數字(0~100)\n\n");
	
	int i , j;
	
	for(i=0;i<64;i++)
	{
		do
		{
			number[i] = rand()%100+1;
			for(j=0;j<i;j++)
			{
				if(number[i] == number[j])
				{
					number[i] = 0;
					break;
				}
			}
		}
		while(number[i] == 0);
	}
	
	for(i=0;i<64;i++)
	{
		printf("%3d ",number[i]);
	}
	printf("\n");
}

void half_sort()
{
    printf("\n");
    printf("分成兩段並排序\n\n");
    int i , j , min , temp;
	
   for (i=0;i<32-1;i++)
   {
      min = i;
      for (j=i+1;j<32;j++)
      {
         if(number[min] > number[j])
         {
            min = j;
         }
      }
      if(min != i)
      {
         temp = number[i];
         number[i] = number[min];
         number[min] = temp;
      }
   }
/*    
    for(i=0;i<32;i++)
    {
       printf("%3d ",number[i]);
    }
    printf("\n");
*/    
    for (i=32;i<63;i++)
   {
      min = i;
      for (j=i;j<64;j++)
      {
         if(number[min] > number[j])
         {
            min = j;
         }
      }
      if(min != i)
      {
         temp = number[i];
         number[i] = number[min];
         number[min] = temp;
      }
   }
/*   
   for(i=32;i<64;i++)
   {
      printf("%3d ",number[i]);
   }
*/   
   for(i=0;i<32;i++)
   {
      printf("%3d ",number[i]);
   }
   printf("\n\n");
   for(i=32;i<64;i++)
   {
      printf("%3d ",number[i]);
   }
   
   printf("\n\n");
}

void find_biggest_numbers()
{
	 printf("分成8段並排序好 找到最大的8個數字集中在一段\n\n");
     int part , a , min;
     part = sqrt(64);
     
     int i , j=31 , k=63 , temp;
     
     int biggest[8] = {0};
     
     
     for(i=0;i<8;i++)
     {
        if(number[j] < number[k])
        {
           biggest[i] = number[k];
           k--;
        }
        else if(number[j] > number[k])
        {
           biggest[i] = number[j];
           j--;
        }
     }
     
      for(i=31;i>23;i--)
     {
        for(j=63;j>55;j--)
        {
        	if(number[i] < number[j])
        	{
        		temp = number[i];
        		number[i] = number[j];
        		number[j] = temp;
			}
		}
     }
     
     for(i=0;i<8;i++)
     {
     	printf("%3d ",biggest[i]);
	 }
     printf("\n\n");
     
     for(a=0;a<64;a=a+8)
     {
        for (i=a;i<a+8;i++)
        {
        min = i;
           for (j=i;j<a+8;j++)
           {
              if(number[min] > number[j])
              {
                 min = j;
              }
           }
           if(min != i)
           {
              temp = number[i];
              number[i] = number[min];
              number[min] = temp;
           }
        }
     }
        j=0;
        for(i=0;i<64;i++)
        {
           printf("%3d ",number[i]);
           j++;
           if(j%8 == 0)
           {            
              printf("\n");
           }
        }
     printf("\n\n");
}

void find_lastnumber_swap()
{
	printf("把最大數字的那一段搬到第1段(交換) 然後找出後7段每段最大的數 並且依據小到大整段排序\n\n");
     int i , j , k , temp ,min;
     
     j=24;
     for(i=0;i<8;i++)
     {
        temp = number[i];
        number[i] = number[j];
        number[j] = temp;
        j++;
     }
     
     for(i=15;i<64;i=i+8)
     {
     	for(j=15;j<64;j=j+8)
     	{
     		if(number[i] <number[j])
     		{
     			for(k=i;k>i-8;k--)
     			{
     				temp = number[k];
     				number[k] = number[j];
     				number[j] = temp;
     				j--;
				}
			}
		}
	 }
     
     j=0;
     for(i=0;i<64;i++)
     {
        printf("%3d ",number[i]);
        j++;
        if(j%8 == 0)
        {            
           printf("\n");
        }
     }
     printf("\n\n");
}

void merge_sort()
{
	 printf("開始合併囉~~\n\n"); 
     int y,z,c,d;
     int i=0 , j=8 , k=16 , temp , min;
     int a,b;
     
     while(k<64)
     {	
        if(k+7 < 63)
        {
        for (c=k;c<k+6;c++)
        {
           min = c;
           for (d=c+1;d<k+7;d++)
           {
              if(number[min] > number[d])
              {
                 min = d;
              }
           }
           if(min != c)
           {
              temp = number[c];
              number[c] = number[min];
              number[min] = temp;
           }
        }
        }
                
        printf("3個點 = %d %d %d\n",i,j,k);
        
        y=0;
        for(z=0;z<64;z++)
        {
          printf("%3d ",number[z]);
          y++;
          if(y%8 == 0)
          {            
             printf("\n");
          }
        }
        printf("\n\n");
     
        system("pause");
        
        printf("\n\n");
                
     	if(j-1 == i)
     	{
     		j = k;
     		while(number[k] < number[k+1])
     		{
     			k++;
     			if(number[k] > number[k+1])
     			{
     				break;
     				k=k-1;
				}
			}
			a=0;
		}
     	
     	if(number[j] < number[k])
           {
              temp = number[i];
              number[i] = number[j];
              number[j] = temp;
              i++;
              j++;
           }
           else
           {
              temp = number[i];
              number[i] = number[k];
              number[k] = temp;
              k++;
              i++;
	      }
     }    
}

void final_sort_out()
{
	printf("最後將最後一段排序\n\n");
     int i , j , k , min , temp;
     
     for (i=56;i<63;i++)
     {
        min = i;
        for (j=i+1;j<64;j++)
        {
           if(number[min] > number[j])
           {
              min = j;
           }
        }
        if(min != i)
        {
           temp = number[i];
           number[i] = number[min];
           number[min] = temp;
        }
     }
     
     j=0;
     for(i=0;i<64;i++)
     {
       printf("%3d ",number[i]);
       j++;
       if(j%8 == 0)
       {            
          printf("\n");
       }
     }
     printf("\n\n");
     
     
    printf("排好囉~\n\n"); 
    for(i=0;i<64;i++)
	{
		printf("%3d ",number[i]);
	}
	printf("\n");
}
