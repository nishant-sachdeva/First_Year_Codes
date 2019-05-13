#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)
#define ll long long int

int main()
{
    ll n; scanf("%lld", &n);
    ll ones =0;
    ll pow = 1;
    ll ai=0, bi=0;
    while( n > 0)
    {
        if( n%2 == 1) 
        {
            if(ai == 0) ai = pow; 
            else bi = pow;
            ones++;
        }
        n /= 2;
        pow *= 2;
    }
    if(ones > 2) printf("No\n");
    else
    {
        if( ones == 1)
        {
            if( ai == 1 ) printf("No\n");
            else printf("Yes\n%lld %lld\n", ai/2, ai/2);
        }
        else
        {
            printf("Yes\n%lld %lld\n", ai, bi);
        }
    }
    return 0;
}

