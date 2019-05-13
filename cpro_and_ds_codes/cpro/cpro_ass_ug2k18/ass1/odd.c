#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)


/*long long int mod( long long int a)
{
    if(a >= 0) return a;
    return -a;
}*/

int main()
{
    long long int n; scanf("%lld", &n);
    long long int ans = 0;
    while(n--)
    {
        long long int i; scanf("%lld", &i);
        ans ^= i;
    }
    if( ans != 0) printf("%lld\n", ans);    
    else printf("-1\n");
    return 0;
}

