
#include<stdio.h>

#define ll long long int
#define geti(n) ll n; scanf("%lld", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

ll maxm( ll a, ll b)
{
    if( a>b) return a;
    return b;
}

int main()
{
    char arr[1000006];
    geti(test); 
    while(test--)
    {
        geti(n); geti(m);
        scanf("%s", arr);
        ll flag1=0, flag2=0, len=0, maxlen= 0, nod=0;
        int j =0;
        for(int i =0 ; i<n ; i++)
        {
            if(arr[i] == 'd') nod++;
	        len =  i - j+1;
            show(len);
            maxlen = maxm( len , maxlen);
            if (nod == m+1)
            {
                for(; j<n ; j++)
                {
                    if(arr[j] == 'd')
                    {
                        nod--; break;
                    }
                }
            }
        }
        show(maxlen);
    }

    return 0;
}

