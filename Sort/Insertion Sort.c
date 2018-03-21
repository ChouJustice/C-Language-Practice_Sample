#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int number[100] = {0};

void random_number();
void selection_sort();

int main(void)
{
	random_number();
	insertion_sort();
	
	printf("\n");
	system("pause");
	return 0;
}

void random_number()
{
	printf("排序前 : \n");
	int i , j;
	
	for(i=0;i<100;i++)
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
		printf("%d ",number[i]);
	}
}

void insertion_sort()
{
	printf("\n排序後 : \n");
    int num[100] = {0};
    int i , j , k , min , temp;
    
    for(i=0;i<100;i++)
    {
    	num[i] = number[i];
	}
    
    for(i=1;i<100;i++)
	{
        temp = num[i];
        for(j=i;j>0&&temp<num[j-1];j--)
        {
           num[j] = num[j-1];
		}
        num[j] = temp;
    }
    
    for(k=0;k<100;k++)
    {
    	printf("%d ",num[k]);
	}
}
