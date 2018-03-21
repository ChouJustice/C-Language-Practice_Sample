#include <stdio.h>
#include <stdlib.h>

int main(void)
{ 
    void swap(int *,int *);
    int a , b , c , d , e , f;
    
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    
    printf(" Before swap = %d , %d , %d , %d , %d , %d\n",a,b,c,d,e,f);
    if(a>b) swap(&a,&b); if(b>c) swap(&b,&c); if(c>d) swap(&c,&d); if(d>e) swap(&d,&e); if(e>f) swap(&e,&f);
    if(a>b) swap(&a,&b); if(b>c) swap(&b,&c); if(c>d) swap(&c,&d); if(d>e) swap(&d,&e);
    if(a>b) swap(&a,&b); if(b>c) swap(&b,&c); if(c>d) swap(&c,&d);
    if(a>b) swap(&a,&b); if(b>c) swap(&b,&c); 
    if(a>b) swap(&a,&b);
    printf("  After swap = %d , %d , %d , %d , %d , %d\n",a,b,c,d,e,f);
    system("pause");
    return 0;
}

void swap(int *x,int *y)
{
    int t;
    
    t = *x;
    *x = *y;
    *y = t;
}
