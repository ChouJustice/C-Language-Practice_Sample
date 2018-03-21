#include <iostream>

using namespace std;

void startWalk(int ) ;
void printHow();

int len = 0, n = 0, total = 0, *step;

int main(void) 
{
    cout << "Input stairs of n = ";
    cin >> n;
    cout << endl;
    if (n!=0 && n>0)
	{
        step = new int [n];
        startWalk(n);
        cout << endl << "Total Path : " << total << endl << endl;
    }
    else return main();
    
    system("pause");
    return 0;
}

void printHow()
{
    cout << "Path "<< total << " ¡÷ " ;
    for (int i = 0; i < len; i++) 
	{
	    cout << step[i] << " ";
    }
    cout <<endl;
    return;
}

void startWalk(int s) 
{
	//cout << s << endl;
    if (s < 0) 
	{
		return;
	}
    else if (s == 0) 
	{
		total++;
        printHow();
        return;
    }
    else
    for (int i = 1; i <= 2; i++) 
    {
        step[len] = i;
        len++;
        //cout << "$" << len << endl;
        startWalk(s - i);
        len--;
        //cout << "*" << len << endl;
        //cout << i << endl;
    }
}
