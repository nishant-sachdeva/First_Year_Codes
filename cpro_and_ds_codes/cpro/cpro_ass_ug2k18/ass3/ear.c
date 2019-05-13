#include<stdio.h>

#define ll long long int
#define get(n) ll n; scanf("%lld", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else                                                                        
        return  gcd(b,a%b);
}


int main()
{
	get(test);
	while(test--)
	{
		get(a);
		get(b);
		get(c);
		ll ans = gcd(a , b);
		if( c%ans == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}