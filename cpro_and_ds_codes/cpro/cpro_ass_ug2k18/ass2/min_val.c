#include<stdio.h>

#define ll long long int
#define geti(n) long long int n; scanf("%lld", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( long long int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

long long int arr[1000006];

int main()
{
    geti(test);
    while(test--)
    {
        geti(n); geti(q);
        loop(0,n+5){ arr[i] = 0;}
        for(int i =0 ; i<q ; i++)
        {
            geti(l) ; geti(r); geti(num);
            arr[l] += num;
            arr[r+1] -= num;
        }
        eloop(1,n) { arr[i] += arr[i-1] ; }
        ll min = arr[1]; ll min_in  =1;
        eloop(2,n){
            if(arr[i] < min)
            { min = arr[i]; min_in = i; }
        }
       show(min_in);
    }
    return 0;
}

