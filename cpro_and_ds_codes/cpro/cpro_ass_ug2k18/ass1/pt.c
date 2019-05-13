#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int main()
{
    int n ; scanf("%d", &n); int count =0;
    for(int i = 1 ; i<n ; i++)
    {
        int n1  = i,n2 = i+1;
        if( n1*n1*n2 <= n && n2*n2*n1 <= n) count++;
        else break;
    }
    printf("%d\n", count);
         
    
    return 0;
}

