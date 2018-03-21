#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void insertNode(int);
void deleteNode(int);
void insertNode_frommiddle(int,int);
void reviseNode(int,int);
void resetNode();
bool searchNode(int);

struct Node
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
		printf("[1]�s�W [2]�R�� [3]���J [4]�ק� [5]���m [6]���} ==> "); 
        scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("\n�п�J�n�[�J���Ʀr ==> ");
				scanf("%d",&temp);
				insertNode(temp);
				break;
			case 2 :
				printf("\n�п�J�n�R�����Ʀr ==> ");
				scanf("%d",&temp);
				deleteNode(temp);
				break;
			case 3 :
	            printf("\n�аݷQ��J�b���@�ӼƦr���� ==> ");
	            scanf("%d",&tempnum);
				printf("�п�J�n���J���Ʀr ==> ");
	            scanf("%d",&temp);
				insertNode_frommiddle(tempnum,temp);
				break;
			case 4 :
				printf("\n�п�J�n�ק諸�Ʀr ==> ");
				scanf("%d",&tempnum);
				printf("�п�J�ק�᪺�Ʀr ==> ");
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

void insertNode(int temp)
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
	printf("�V�k�L�X ");
	while(now->rlink!=head)
	{
	    now=now->rlink;
	    printf("%d ",now->data);
	}
	printf("\n");
	now=head;
	printf("�V���L�X ");
	while(now->llink!=head)
	{
	  	now=now->llink;
	    printf("%d ",now->data);
	}
	
	printf("\n\n");
}

void deleteNode(int temp)
{
	now = head;
	if(node_number==0)
	{
		printf("�ާ@����!(�L�Ʀr�i�R)\n");
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
			printf("�ާ@����!(�L���Ʀr)\n");
		}
	}
	
	now=head;
	printf("�V�k�L�X ");
	while(now->rlink!=head)
	{
	    now=now->rlink;
	    printf("%d ",now->data);
	}
	printf("\n");
	now=head;
	printf("�V���L�X ");
	while(now->llink!=head)
	{
	  	now=now->llink;
	    printf("%d ",now->data);
	}
	
	printf("\n\n");
}

bool searchNode(int temp)
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
			printf("�ާ@���~!(�L�� %d �Ʀr)\n",tempnum);
		}
	}
	
	now=head;
	printf("�V�k�L�X ");
	while(now->rlink!=head)
	{
	    now=now->rlink;
	    printf("%d ",now->data);
	}
	printf("\n");
	now=head;
	printf("�V���L�X ");
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
		printf("�ާ@����!(�L�Ʀr�i�ק�)\n");
	}
	else
	{
		if(searchNode(tempnum)==true)
		{
			now->data=temp;
		}
		else
		{
			printf("�ާ@����!(�L���Ʀr)\n");
		}
	}
	
	now=head;
	printf("�V�k�L�X ");
	while(now->rlink!=head)
	{
	    now=now->rlink;
	    printf("%d ",now->data);
	}
	printf("\n");
	now=head;
	printf("�V���L�X ");
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
