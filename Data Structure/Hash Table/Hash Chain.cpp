#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<fstream>
#include<windows.h>
using namespace std;

void File_open(string &);
void display();

char filename[25]={0};
string article,sname;
char word[6];
char words[6000];
int function[1000];
int number;


struct hash *hashTable = NULL;
 
struct node
{
    int num, datanum;
    char data[6];
    struct node *next;
};
 
struct hash
{
    struct node *head;
    int count;
};

struct node * createNode(int num, char *data, int datanum) 
{
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->num = function[num];
    newnode->datanum = function[datanum];
    strcpy(newnode->data, data);
    newnode->next = NULL;
    return newnode;
}
 
void insertToHash(int num, char *data, int datanum) 
{
    int hashIndex = function[num];
    struct node *newnode = createNode(num, data, datanum);

    if (!hashTable[hashIndex].head) 
	{
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }

    newnode->next = (hashTable[hashIndex].head);

    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}
 
void searchInHash(char data[6]) 
{
	char t[6];
	char s[6];
	int i,j=1;
	int n=0;
	int loc = 1;
	
	strcpy(t,data);
	strcpy(s,data);
	
	for(i=0;i<6;i++)
	{
		while(j != 60)
		{
			if(j == 1)
		      {
		      	  //printf("\n%c %d",t[i],t[i]);
		      	  n = n + ( t[i] * j );
		      	  //printf("  %d",t[i]*j);
		      	  j = 10;
		      	  break;
			  }
			  else
			  {
			  	  //printf("\n%c %d",t[i],t[i]);
   	   	          n = n + ( t[i] * j );
   	   	          //printf("  %d",t[i]*j);
   	   	          j = j + 10;
   	   	          break;
   	   	      }
		}
	}
	
	n = n % 997;
	
	//printf("\n%d\n",n);
	//printf("\n%s\n",s);
	
    int hashIndex = n , flag = 0;
    struct node *myNode;
    myNode = hashTable[hashIndex].head;
    
    if (!myNode) 
	{
        printf("Search element unavailable in hash table\n");
        return;
    }
    
    while (myNode != NULL) 
	{
		strcpy(t,myNode->data);
		//printf("\n%s  %s\n",t,s);
        if (strcmp(t, s) == 0)
		{
            printf("Hash_Head  : %d\n", myNode->num);
            printf("Data       : %s\n", myNode->data);
            printf("Function   : %d\n", myNode->datanum);
            printf("Search Time: %d\n",loc);
            flag = 1;
            break;
        }
        myNode = myNode->next;
        loc++;
    }
    if (!flag)
        printf("Search element unavailable in hash table\n");
    return;
}
 
void display() 
{
    struct node *myNode;
    int i;
    int count=0;
    number=0;
    
    for (i = 0; i < 1000; i++) 
	{
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (!myNode)
            continue;
        //printf("\nData at index %d in Hash Table:\n", i);
        //printf("Hash_Head    Data       Function   \n");
        //printf("--------------------------------\n");
        printf("\n");
        printf("Hash Table %3d -> ", myNode->datanum);
        while (myNode != NULL)
		{
			count++;
            //printf("%-12d", myNode->num);
            printf("%-9s", myNode->data);
            //printf("  %3d", myNode->datanum);
            myNode = myNode->next;
            //printf("\n%d\n",count);
            number = number + count;
        }
        count = 0;
        //printf(" %3d",number);
    }
    return;
}

void File_open(string &article)
{

   FILE *fp;
   char ch;
   int x=0;
   int i=0 , j=0;
   
   cout << "請輸入檔名: ";
   cin >> filename;
      
   fp = fopen(filename,"r");
   while(1)   //計算字數 
   {
      ch = getc(fp);
      if(ch == EOF) break;
      {
         x++;
      }
   }
   
   char txt[x];
   for(j=0;j<=x;j++)
   {
      txt[j] = 0;
   }
   
   fp = fopen(filename,"r");
   while(1)
   {
   	  ch = getc(fp);
      if(ch == EOF) break;
      {
   	     txt[i] = ch;
      }
      i++;
   }
    
   article.assign(txt); //替換字串 
   
   //cout << "\n" << article << "\n";
   
   j=0;
   for(i=0;i<x;i++)
   {
   	   if(txt[i] != ' ' && txt[i] != '\n')
   	   {
   	   	   words[j] = txt[i];
   	   	   j++;
	   }
   }
   /*
   for(i=0;words[i]!=0;i++)
   {
   	   printf("%c",words[i]);
   }
   */
   int k=0;
   int n=1;
   for(i=0;words[i]!=0;i=i+6)
   {
   	   for(j=i;j<i+6;j++)
   	   {
   	   	   while(n != 60)
		   { 
		      if(n == 1)
		      {
		      	  //printf("\n%c %d",words[j],words[j]);
		      	  function[k] = function[k] + ( words[j] * n );
		      	  //printf("  %d",words[j]*n);
		      	  n = 10;
		      	  break;
			  }
			  else
			  {
   	   	         //printf("\n%c %d",words[j],words[j]);
   	   	         function[k] = function[k] + ( words[j] * n );
   	   	         //printf("  %d",words[j]*n);
   	   	         n = n + 10;
   	   	         break;
   	   	      }
   	   	   }
	   }
	   function[k] = function[k] % 997;
	   n=1;
	   k++;
   }  
   
   
   //printf("\n%d %d",function[0],function[1]);
   printf("\n");
   
   return;
}

int main(void)
{
	function[1000] = 0;
	words[6000] = 0;
	number = 0;
	File_open(article);
//	eleCount = 1000;
	hashTable = (struct hash *) calloc(6000, sizeof(struct hash));
	int i=0,j=0,k=0,z=0;
	char temp[6];
	temp[6] = 0;
	char t[6];
	
	for(k=0;k<1000;k++)
	{
	   for(j=j;words[j]!=0;j=j)
	   {
          for(i=j;i<j+6;i++)
	      {
	      	  while(z!=6)
	      	  {
	      	  	 temp[z] = words[i];
	      	  	 break;
			  }
			  z++;
	      }
	    strcpy(t,temp);
	    insertToHash(k, t, k);
	    //display();
	    j=j+6;
	    z=0;
	    break;
       }
    }
    
    display();
    cout << "\n\nFunction : ( 1*A + 10*B + 20*C + 30*D + 40*E + 50*F ) % 997 \n";
    cout << "Data insert to HashTable successful!!!"; 
    
    //printf("\n%d\n",number);
    
    float avg;
    
    avg = number / 1000.0;
    
    printf("\nAverage is %1.2f\n",avg);
	
	while(1)
	{
	   char s[6];
	   printf("Enter the data of node: ");
       cin >> s;
       strcpy(t,s);
       printf("\n");
       searchInHash(t);
       printf("\n");
    }
	
	
	system("pause");
	return 0;
}
