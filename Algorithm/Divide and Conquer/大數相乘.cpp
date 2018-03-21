#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std ;
#define SIZE 1024

char filename[20]={0};
int s[2] = {0};
int size;
int k=0;


class Bigint //大數 
{
	private:
    public:
            int Num[SIZE];
            Bigint();
            Bigint & operator = (string s1 );
            Bigint & operator = (const int & );
};
Bigint::Bigint()  // 初始化 
{
        for( int i = 0 ; i < SIZE ; i++ )
        {
			Num[i] = 0;
		}
}

Bigint & Bigint::operator = ( const string s1 ) // Bigint = string 
{
        int count = 0 ;
        for( int i = ( s1.size()- 1 ) ; i >= 0  ; i-- )
        {
            Num[count] = s1[i] - '0';
            count++ ;
        }
        return *this;
}

Bigint & Bigint::operator = ( const int &a )  // 判斷進位
{
        Num[0] = a;

        for( int i = 0 ; i < SIZE ; i++ )
        {
            Num[i+1] += Num[i] / 10;    
            Num[i] %= 10;
        }
        return *this;
}

ostream& operator << ( ostream &out , Bigint &a ) // out print
{
        int i = SIZE - 1;
        while (i >= 0 && a.Num[i] == 0) i--;

        if (i < 0)
        {
            out << '0';
        }
        else
        {
            while (i >= 0)
            {
                out << a.Num[i--];
            }
        }
        return out;
}

Bigint operator * ( const Bigint &a , const Bigint &b )  // Bigint * Bigint
{
        Bigint c;

        for( int i = 0 ; i < SIZE ; i++ )
        {
            for( int j = 0 ; j < SIZE ; j++ )
            {
                if( ( i + j ) < SIZE )
                {
                    c.Num[i+j] += a.Num[i] * b.Num[j];
                }
            }
        }

        for( int i = 0 ; i < SIZE ; i++ )  // 判斷進位 
        {
            c.Num[i+1] += c.Num[i] / 10;    
            c.Num[i] %= 10;
        }
        return c;
}

Bigint operator * ( const Bigint &a , const int b ) // Bigint * int
{
        Bigint c;

        for( int i = 0 ; i < SIZE ; i++ )
        { 
            c.Num[i] = a.Num[i] * b;
        } 

        for( int i = 0 ; i < SIZE ; i++ )
        {
            c.Num[i+1] += c.Num[i] / 10;    // 判斷進位
            c.Num[i] %= 10;
        }
        return c;
}

Bigint operator + ( const Bigint &a , const Bigint &b ) // Bigint + Bigint
{
        Bigint c;

        for( int i = 0 ; i < SIZE ; i++ )
        { 
            c.Num[i] = a.Num[i] + b.Num[i];
        } 
        for( int i = 0 ; i < SIZE ; i++ ) // 判斷進位
        {
            c.Num[i+1] += c.Num[i] / 10;    
            c.Num[i] %= 10;
        }
        return c;
}

inline bool operator == ( const Bigint &a , const Bigint &b ) // Bigint == Bigint 時 
{
        for( int i = SIZE - 1 ; i >= 0 ; i++ )
        { 
            if( a.Num[i] != b.Num[i] )
            return false;
        } 
        return true;
}

inline bool operator == ( const Bigint &a , const int &b ) // Bigint == int 時  
{
        Bigint c;
        c = b;

        if( a == c )
        { 
            return true;
        } 
        else
        { 
            return false ;
        } 
}

Bigint ten_n_Power ( int );

Bigint File_open();

Bigint Devide( Bigint , Bigint , int );

int main(void)
{
	Bigint a , b , c , ans;
	
	cout << "大數 A " << endl; a = File_open();
	cout << "大數 B " << endl; b = File_open();
	
	cout << endl << "size = " << size << endl;
	system("pause");
	int bug = 0;
	
	bug = size;  // 當size被割成 5 時  會有BUG 
	while(1)
	{
		bug = bug / 2;
		if(bug == 5) break;
		if(bug == 1) break;
	}
	
	if(bug == 5)
	{
		ans = a * b;
	}
	else
	{
		ans = Devide(a  , b , size) ;
    }
	cout << "Answer = " << endl << endl << ans << endl;
	
	cout << endl;
	system("pause");
	return 0;
}

Bigint File_open()
{	
   	FILE *fp;
   	char ch;
   	int x=0;
   	int i=0 , j=0;
   
   	cout << " 請輸入檔名 : ";
   	cin >> filename;
      
   	fp = fopen(filename,"r");
   	while(1)   //計算字數 
   	{
      	ch = getc(fp);
      	if(ch == EOF) break;
      	{
      		if(ch != ' ' && ch != '\n') x++;
      	}
   	}
   	
   	char num[x+1];
   	
   	for(j=0;j<x;j++)
   	{
      	num[j] = '0';
   	}
   	num[x] = '\0';
   
   	fp = fopen(filename,"r");
   	while(1)
   	{
   	  	ch = getc(fp);
      	if(ch == EOF) break;
      	{
   	 	  	if(ch != ' ' && ch != '\n') 
		  	{
			 	num[i] = ch;
			 	//printf("i = %d = %c",i,num_A[i]);
			 	i++;
		  	}
      	}
   	}
   	// size 取得 
   	s[k] = x; k++;
   	
	int t=0;
  	if(s[t] > s[t+1]) 
	{
		size = s[t];
    }
    else
    {
    	size = s[t+1];
	}
  	
	  
	cout << endl << "size = " << x << endl << endl; 
	  
	Bigint a; 
	
	a = num;	
	
	cout << a << endl << endl;
	
	return a;
}

Bigint ten_n_Power ( int n )  // 10^size 
{
        Bigint a ;
        a = 1;
        for( int i = 0 ; i < n ; i++ )
        { 
            a = a * 10;
        } 
        return a;
}

Bigint Devide( Bigint a , Bigint b ,int s)
{
        Bigint w , x , y , z  , zero;
        int n , m;
        zero = 0;
        n = s;
        //cout << "n = " << n << endl ;
        //cout << "a = " << u << endl ;
        //cout << "b = " << v << endl ;
        
        //system("pause");
        if( a == 0 || b == 0 )
        {
            return zero;
        }
        else if ( n <= 4 )
        {
            return a * b;
        }
        else
        {

                //cout << ".................................................................." << endl ;
                m = n / 2;
                int loc = m - 1;

                //cout << "m = " << m << endl;
                //cout << "loc = " << loc << endl;

                for( int i = n - 1 ; i >= m ; i-- )
                {
                        x.Num[loc] = a.Num[i];
                        w.Num[loc] = b.Num[i];
                        loc--;
                }

                //cout << "x = " << x << endl ;
                //cout << "w = " << w << endl ;

                for( int i = m - 1 ; i >= 0 ; i-- )
                {
                        y.Num[i] = a.Num[i];
                        z.Num[i] = b.Num[i];
                }
                //cout << "y = " << y << endl ;
                //cout << "z = " << z << endl ;

                Bigint p , q , r , merge;

                p = Devide( x , w , s/2) * ten_n_Power(2 * m);
                q = ( Devide(w , y, s/2) + Devide(x , z ,s/2)) * ten_n_Power(m);
                r = Devide(y , z , s/2);
                
                merge = p + q + r;

                //cout << "p = " << p << endl;
                //cout << "q = " << q << endl;
                //cout << "r = " << r << endl;

                return merge;
        }
}

