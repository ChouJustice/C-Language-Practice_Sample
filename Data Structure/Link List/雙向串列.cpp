#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void insertNode(int);
void deleteNode(int);
void insertNode_frommiddle(int,int);
void reviseNode(int,int);
void resetNode();
bool searchNode(int);

struct Node  //節點資料
{
	int data;
	struct Node*rlink;
	struct Node*llink;
};
typedef struct Node PtrNode;
typedef PtrNode *ptr;
ptr head=NULL;
ptr now=NULL;

int node_number = 0;

int main(void)
{
	head=(ptr)malloc(sizeof(PtrNode));
    now=(ptr)malloc(sizeof(PtrNode));
	int choice;
	int temp,tempnum;
	
	while(choice != 6)
	{
		printf("[1]新增 [2]刪除 [3]插入 [4]修改 [5]重置 [6]離開 ==> "); 
        scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("\n請輸入要加入的數字 ==> ");
				scanf("%d",&temp);
				insertNode(temp);
				break;
			case 2 :
				printf("\n請輸入要刪除的數字 ==> ");
				scanf("%d",&temp);
				deleteNode(temp);
				break;
			case 3 :
	            printf("\n請問想輸入在哪一個數字之後 ==> ");
	            scanf("%d",&tempnum);
				printf("請輸入要插入的數字 ==> ");
	            scanf("%d",&temp);
				insertNode_frommiddle(tempnum,temp);
				break;
			case 4 :
				printf("\n請輸入要修改的數字 ==> ");
				scanf("%d",&tempnum);
				printf("請輸入修改後的數字 ==> ");
				scanf("%d",&temp);
				reviseNode(tempnum,temp);
				break;
			case 5 :
				resetNode();
				break;
		}  
	}
	
	
	system("pause");
	return 0;
}

void insertNode(int temp) //新增節點
{
	now = head;
	ptr newnode;
	int tail_data;
	newnode=(ptr)malloc(sizeof(PtrNode));
	if(node_number==0)
	{
		head->rlink=newnode;
		head->llink=newnode;
		newnode->data=temp;
		newnode->rlink=head;
		newnode->llink=head;
		node_number++;
	}
	else
	{
		tail_data=head->llink->data;
		if(searchNode(tail_data)==true)
		{
			newnode->data=temp;
			newnode->rlink=now->rlink;
			now->rlink->llink=newnode;
			now->rlink=newnode;
			newnode->llink=now;
			node_number++;
		}
	}
	
	now=head;
	printf("向右印出 ");
	while(now->rlink!=head)
	{
	    now=now->rlink;
	    printf("%d ",now->data);
	}
	printf("\n");
	now=head;
	printf("向左印出 ");
	while(now->llink!=head)
	{
	  	now=now->llink;
	    printf("%d ",now->data);
	}
	
	printf("\n\n");
}

void deleteNode(int temp) //刪除節點
{
	now = head;
	if(node_number==0)
	{
		printf("操作失敗!(無數字可刪)\n");
	}
	else
	{
		if(searchNode(temp)==true)
		{
			now->llink->rlink=now->rlink;
			now->rlink->llink=now->llink;
			node_number--;
		}
		else
		{
			printf("操作失敗!(無此數字)\n");
		}
	}
	
	now=head;
	printf("向右印出 ");
	while(now->rlink!=head)
	{
	    now=now->rlink;
	    printf("%d ",now->data);
	}
	printf("\n");
	now=head;
	printf("向左印出 ");
	while(now->llink!=head)
	{
	  	now=now->llink;
	    printf("%d ",now->data);
	}
	
	printf("\n\n");
}

bool searchNode(int temp) //搜尋節點
{
	now = head;
    for(int i=0;i<node_number;i++)
    {
    	now=now->rlink;
    	if(now->data==temp)
    	{
    	    return true;
    	}
	}
	return false;
}

void insertNode_frommiddle(int tempnum,int temp)
{
	now = head;
	ptr newnode;
	newnode=(ptr)malloc(sizeof(PtrNode));
	if(node_number!=0)
	{
		if(searchNode(tempnum)==true)
		{
			newnode->data=temp;
			newnode->rlink=now->rlink;
			now->rlink->llink=newnode;
			now->rlink=newnode;
			newnode->llink=now;
			node_number++;
		}
		else
		{
			printf("操作錯誤!(無此 %d 數字)\n",tempnum);
		}
	}
	
	now=head;
	printf("向右印出 ");
	while(now->rlink!=head)
	{
	    now=now->rlink;
	    printf("%d ",now->data);
	}
	printf("\n");
	now=head;
	printf("向左印出 ");
	while(now->llink!=head)
	{
	  	now=now->llink;
	    printf("%d ",now->data);
	}
	
	printf("\n\n");
}

void reviseNode(int tempnum , int temp)
{
	now = head;
	if(node_number==0)
	{
		printf("操作失敗!(無數字可修改)\n");
	}
	else
	{
		if(searchNode(tempnum)==true)
		{
			now->data=temp;
		}
		else
		{
			printf("操作失敗!(無此數字)\n");
		}
	}
	
	now=head;
	printf("向右印出 ");
	while(now->rlink!=head)
	{
	    now=now->rlink;
	    printf("%d ",now->data);
	}
	printf("\n");
	now=head;
	printf("向左印出 ");
	while(now->llink!=head)
	{
	  	now=now->llink;
	    printf("%d ",now->data);
	}
	
	printf("\n\n");
}

void resetNode()
{
	now = head;
	head->rlink->llink=head;
	head->llink->rlink=head;
	node_number=0;
	
	now = head;
	
	printf("\n\n");
}
