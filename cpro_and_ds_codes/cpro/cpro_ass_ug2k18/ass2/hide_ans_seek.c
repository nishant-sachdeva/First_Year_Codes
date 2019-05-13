#include<stdio.h>

#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)
#define ll long long int


ll mul( ll x ,  ll y , ll mod)
{
    ll ans = 0;
    x %=mod;
    while(y)
    {
        if( y%2 ==1)
        {
           ans = (ans + x) %mod;
        }
        y /= 2;
        x = (x*2)%mod;
    }
    return ans%mod;
}


int main()
{
    geti(test);
    while(test--)
    {
        geti(n);
        unsigned long long int mod, ans=1;  scanf("%lld", &mod);
        loop(0,n)
        {
            ll x, y, med =1 ;
            scanf("%lld %lld", &x, &y);
            if( x%2==0)
            {
                if( y %2 == 0)
                    ans*= mul(mul(x/2,x+1,mod) , mul(y/2,y+1,mod), mod) %mod;
                else 
                    ans*= mul(mul(x/2,(x+1),mod) , mul(y,(y+1)/2,mod), mod) %mod;
            }
            else
            {
                if( y %2 == 0)
                    ans*= mul(mul(x,(x+1)/2,mod) , mul(y/2,y+1,mod), mod) %mod;
                else 
                    ans*= mul(mul(x,(x+1)/2,mod), mul(y,(y+1)/2,mod), mod) %mod;
            }
           
            //show(med)
            //show(ans);
            ans %= mod;

            //show(med);

            ans %= mod;
        }
        ans %= mod;
        show(ans);
    }
    return 0;
}

