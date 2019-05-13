#include<stdio.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

ll c[510][510] = {0};

/*ll find(ll n, ll m, ll mod)
{
	for(int i = 1 ; i<=n ; i++)
	{
		for(int j = 1; j<=i &&j<=m; j++)
		{
			c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
		}
	}
	return c[n][m]%mod;
}*/



int main()
{
	for(int i = 0; i<510 ; i++)
		c[i][0] = 1;	
	get(test);
	while(test--)
	{
		get(n);
		get(m);
		get(mod);
		//assuming that n is bigger or equal to m;
		if(n<m)
			printf("0\n"); 
		else
		{
			ll done[510] = {0};
			ll sum = 0;
			for(int i = m-1 ; i<= n-1 ; i++)
			{
				//sum = (sum + find(i,m-1,mod))%mod;
				for(int j = 1 ; j<=i ; j++)
				{
					if(done[j] == 1)continue;
					else
					{
						done[j] = 1;
						for(int k =1  ; k<=i && k<=m-1 ; k++)
						{
							c[j][k] = (c[j-1][k] + c[j-1][k-1])%mod;
						}
					}
				}
				sum = (sum + c[i][m-1])%mod;
			}
			show(sum%mod);
		}
	}
	

	return 0;
}