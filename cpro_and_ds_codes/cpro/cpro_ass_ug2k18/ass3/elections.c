#include<stdio.h>

#define ll long long int
#define get(n) ll n; scanf("%lld", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

ll mul(ll x, ll y, ll mod){

}


int main()
{
	get(n); get(mod);
	ll x=0, y=0;
	for(ll i =0; i<n ; i++){
		get(xi); get(yi);
		if(yi == 0) x++;
		else if(xi == 0 ) y++;
	}
	
	// ans is nc3 - xc3 - yc3;
	
	ll ans;

	ans  = n*(n-1)*(n-2) -x*(x-1)*(x-2) - y*(y-1)*(y-2);
	ans /= 6;

	show(ans%mod);

	return 0;
}