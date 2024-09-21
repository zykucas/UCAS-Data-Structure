#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int k, int m)
{
    if(m<k-1) return 0;
    else if(m==k-1) return 1;
    else
    {
        int i;
        int fm=0;
        for(i=m-1;i>=(m-k);i--)
            fm += Fibonacci(k, i);
        return fm;
     }
}
void main()
{
    int k, m, fm;
    scanf("%d %d", &k,&m);
    fm = Fibonacci(k, m);
    printf("%d", fm);
}
