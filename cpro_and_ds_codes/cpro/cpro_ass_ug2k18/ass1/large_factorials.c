#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)
#define ll long long int


ll calc( ll x, ll y, ll m)
{
    if( y == 0) return 1;
    else if ( y == 1) return x%m;
    else
    {   
        if( y % 2 ==0 )
        { return ((calc(x,y/2,m)%m) * (calc(x,y/2,m)%m) ) ;}
        else
        { return (x%m *(calc(x,y/2,m)%m) * (calc(x,y/2,m)%m) ); }
    }   
}

int main()
{
    int test; scanf("%d", &test);
    while(test--)
    {
        ll x,y,m;
        scanf("%lld%lld%lld", &x, &y, &m);
        ll a = x;
        for(int i =0 ; i<y ; i++){
            a =  calc ( a, y-i, m);
        }
        printf("%lld\n", a);
    }
    return 0;
}

