#include <iostream> 
#include <math.h>
#include <iomanip> 
using namespace std;

int size;
int adjacent_matrix[20][20];
int visit[20];
int t = 0;
int low[20];
int articulation=0;
int num=0;

void read_Matrix();
void DFS(int ,int );
void articulation_vertex();
void print();

int main(void)
{
	read_Matrix();
	articulation_vertex();
		
	cout << "\n";	
	system("pause");
	return 0;
}

void read_Matrix()
{
  char filename[50];
  FILE *fp;
  int words;
  int i,j;
  int ch;

  printf("請輸入檔名 : ");
  gets(filename);
 
  fp = fopen(filename,"r");

  if (fp == NULL) printf("開讀檔失敗!");
  else 
  {   
    while(1)   
    {
      ch = getc(fp);
      if(ch == EOF) break;
      else if(ch != EOF)
      {
         words = words + 1;
      }
    }
  }
  //size =sqrt(words/2);
  size = 16;
  cout << size << " * " << size << "\n";
  
  fp = fopen(filename,"r");
  
  //int adjacent_matrix[size][size] = {0};
  
  	 for(i=0;i<size;i++)
  	 {
  	 	for(j=0;j<size;j++)
  	 	{
  	 		fscanf(fp, "%d", &ch);
  	 		adjacent_matrix[i][j] = ch;
		}
	 }
  
  	 for(i=0;i<size;i++)
  	 {
  	 	for(j=0;j<size;j++)
  	 	{
  	 		cout << adjacent_matrix[i][j] << " ";
		}
		cout << "\n";
	 }
	 cout << "\n";
}

void DFS(int p, int i)
{
    visit[i] = low[i] = ++t;
 
    int child = 0;
    bool ap = false;
 
    for (int j=0; j<size; j++)
    {
        if (adjacent_matrix[i][j] && j != p)
        {
            if (visit[j])
            {
                low[i] = min(low[i], visit[j]);
                //cout << visit[j] << "  " << low[i] << "\n";
            }
            else
            {
                child++;
                DFS(i, j);
                low[i] = min(low[i], low[j]);
                if (low[j] >= visit[i]) ap = true;
                //cout << visit[j] << "  " << low[i] << "\n";
            }
        }
    }
    
    if (i == p && child > 1 || i != p && ap)
    {
    	articulation++;
    	if(articulation == 1 && num == 0)
        {
    	    print();
    	    num = 1;
	    }
	    
        cout << i << "是關節點\n";
    }
    
    if(articulation == 1 && num == 0)
    {
    	print();
    	num = 1;
	}
	
	
}

void articulation_vertex()
{
    for (int i=0; i<size; i++)
    {
        if(!visit[i])
        {
            DFS(i, i);
        }
    }
}

void print()
{
	cout << "\n";
	cout << "dot : ";
	for(int i=0;i<size;i++)
	{
		cout << setw(2) << i << " ";
	}
	cout << "\n\n";
	cout << "dfn : ";
	for(int i=0;i<size;i++)
    {
    	cout << setw(2) << visit[i] << " ";
	}
	cout << "\n\n";
	cout << "low : ";
	for(int i=0;i<size;i++)
    {
    	cout << setw(2) << low[i] << " ";
	}
	cout << "\n\n";
}
