#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;

void File_open(string& , string&);
void Morris_Pratt(string& , string& );
void Print_final();
void SetColor(int ,int );
int failure[50];
int word_number[50] = {0};
char filename[10]={0};
string article , word;

int main(void)
{
	File_open(article,word);
    
	Morris_Pratt(article,word);
	
	Print_final();
	
	system("pause");
	return 0;
} 

void File_open(string& article , string& word)
{
   FILE *fp;
   char ch;
   int x=0;
   int i=0 , j=0;
   
   cout << "�п�J�ɦW: ";
   cin >> filename;
      
   fp = fopen(filename,"r");
   while(1)   //�p��r�� 
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
    
   article.assign(txt);
   
   char temp[50] = {0}; 
   cout << "\n" << article;
   
   cout << "\n\n�п�J�A�n�䪺�r��: ";
   cin >> temp;
   
   word.assign(temp);
   
   cout << "\n\n";
}

void Morris_Pratt(string& article, string& word)
{
    if (word.size() > article.size()) return;
    //failure function�C
    for (int i=1, j=failure[0]=-1; i<word.size(); i++)
    {
        while (j >= 0 && word[j+1] != word[i])
        {
           j = failure[j];
        }
        if (word[j+1] == word[i]) j++;
        failure[i] = j;
    }
    cout << "Failure function : ";
    for(int k=0; k<word.size();k++)
	{
		cout << failure[k];
	}
    cout << "\n\n";
    // �r��ǰt�C
    int find;
    int number=0;
	for (int n=0, i=0, j=-1; i<article.size(); i++)
    {
        while (j >= 0 && word[j+1] != article[i])
        {
           j = failure[j];
        }
        if (word[j+1] == article[i]) j++;
 
        if (j == word.size()-1)
        {
        	find = i - word.size() + 1;
        	word_number[n] = find;
        	number++;
            n++;
            j = failure[j];
        }
    } 
    cout << "�@�� " << number << "��  ���\n\n";
}

void Print_final()
{	
    if(word_number[0] != '\0')
    {
	   int i=0 ,j=0 ,n=0;
	   while(article[i] != '\0')
	   {	
	      if(i == word_number[n])
	      {
	   	     for(j=1;j <= word.size();j++)
	   	     {
	   	        SetColor(7,4);  
	   	        cout << article[i];
	   	        i++;
	   	        SetColor(7,0);
	         }  
	         n++;
	      }
	      else
	      {
	   	     SetColor(7,0);
	   	     cout << article[i];
	         i++;
	      }
	   }		
	    cout << "\n\n";
    }
    else
    {
    	cout << "\n�d�L���r��\n\n";
	}
}

void SetColor(int f=7,int b=0)
{
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}
