#include<stdio.h>

#define ll long long int
#define get(n) ll n; scanf("%lld", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( ll i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

ll p[1000006];
ll q[1000006];

int main()
{
    get(test);
    while(test--)
    {
        get(n); get(m); get(k);
        ll max=0;
        loop(0,10000) { p[i] =0; q[i] =0;}
        loop(0,n) { scanf("%lld", &p[i]); } 
        loop(0,m) { scanf("%lld" , &q[i]); }
        ll lena=0, lenb=0, len =0, maxlen =0;
        if(n>=m)
        {
            for(int a =0 ; a<n ;a++)
            {
                lena =1;
                lenb =0;
                while(p[a+1] == p[a])
                {
                    a++; lena++;
                }
                for(int b =0 ; b<m ; b++)
                {
                    if(q[b] == p[a])
                    {
                        while(q[b] == p[a])
                        {
                            lenb++ ;b++;
                            len = lenb<=lena?lenb:lena;
                            maxlen = len >= maxlen?len:maxlen ;
                            if(b>=m) break;
                        }
                        lenb =0;
                    }
                }
            }}
        else
        {
            for( int b =0 ;b<m ; b++)
            {
                lenb = 1; lena =0;
                while(q[b+1] == q[b])
                {b++; lenb++;}
                for(int a=0 ; a<n ; a++)
                {
                    if(p[a] == q[b])
                    {
                        while(p[a] == q[b])
                        {
                            lena++; a++;
                            len = lenb<=lena?lenb:lena;
                            maxlen = len>=maxlen?len:maxlen;
                            if(a>=n) break;
                        }
                        lena =0;
                    }
                }
            }
        }
        show(maxlen*k);
    }
    return 0;
}
