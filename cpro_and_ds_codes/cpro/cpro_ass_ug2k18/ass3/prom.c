#include<stdio.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

ll arr[10004]={0};

int main()
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2 ; i < 10004  ; i++)
	{
		if(arr[i] == 0)//which means it is prime
		{
			for (int j = 2 ; i*j <=10003 ; j++)
			{
				arr[i*j] = 1;
			}
		}
	}
	// here the sieve is ready
	get(test);
	while(test--)
	{
		get(n);
        ll count[10004] = {0};
		for(int i = 0 ; i<n ; i++)
        {
            get(ni);
            if(arr[ni] == 0) { count[ni] = 1;}
            else
            {
            	for(int j = 1 ; j*j <= ni  ; j++)
            	{
            		//printf("checking for %d\n",j );
            		//which means it's a prime number
                    if( ni%j == 0)
                    {
                      	if(arr[j] == 0)
                       		{ count[j] = 1; }
                     	if( arr[ni/j] == 0)
                    		{ count[ni/j] = 1;}
                    }
            	}
            }
        }
        ll c = 0;
        for(int i=2; i <= 10003 ; i++)
        {
        	if(count[i] == 1)
            	{ c++; }
        }
        printf("%lld\n",c );
	}
	return 0;
}
