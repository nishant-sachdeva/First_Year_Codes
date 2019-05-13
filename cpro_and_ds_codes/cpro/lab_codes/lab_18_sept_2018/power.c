#include<stdio.h>
#define ll long long int 

ll calc( ll x, ll y, ll m)
{
	if( y == 0) return 1;
	else if ( y == 1) return x%m;
	else
	{
		if( y % 2 ==0 )
		{ return ((calc(x,y/2,m)%m) * (calc(x,y/2,m)%m) ) %m;}
		else 
		{ return (x%m *(calc(x,y/2,m)%m) * (calc(x,y/2,m)%m) )%m; }
	}
}


int main()
{
	ll x,y,m;
	scanf("%lld%lld%lld", &x, &y, &m);
	ll ans = calc( x,y,m);
	printf("%lld\n", ans);
	return 0;
}
	
