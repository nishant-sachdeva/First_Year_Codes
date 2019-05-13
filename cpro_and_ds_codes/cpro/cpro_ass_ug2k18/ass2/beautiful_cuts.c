#include<stdio.h>


#define geti(n) ll n; scanf("%lld", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( ll i=a ; i<b ; i++)
#define eloop(a,b) for(ll i=a ; i<=b ; i++)
#define ll long long int
#define INT_MIN -10000000009

ll maxm( ll a , ll b)
{
    if(a>b) return a;
    return b; 
}


int main()
{
    geti(test);
    while(test--)
    {
        ll arr[10004];
        geti(num);
        geti(k); 
        long long int sum =0;
        ll check =0;
        loop(0,num) 
        { 
            geti(ni);  
            if(ni >= 0) 
                check = 1; 
            arr[i] = ni; 
            sum  += ni; 
        }
        //show(sum);
        if(k == 0)
        {
            //show(k);
            ll ans =0;
            loop(0,num) { ans += arr[i] ;}
            show(ans);
        }
        else
        {
            if( check == 0)
            {
                //show(2*k);
                ll max = -10000000005;
                loop(0,num) { if(arr[i] > max) { max= arr[i];} }
                show(max);
            } 
            else
            {
                //show(k);
                if( k == 1)
                {
                    ll max = INT_MIN;
                    ll inter =0;
                    loop(0,num-1)
                    {
                        inter += arr[i];
                        sum -= arr[i];
                        max = maxm( max, maxm( sum , inter));
                    }
                    show(max);
                    /*ll max =INT_MIN;
                    loop(0,num-1)
                    {
                        show(sum);
                        show(max);
                        sum -= arr[i];
                        if (sum > max) max = sum;
                    }
                    show(max);*/                    
                }
                else
                {
                    // here basically what we have to do is to find the subarray with the max sum
                    //n^2 algo is slow so we'll have to learn the kadane algo
                    /*  so here is the logic, if sum goes to < 0 set it to 0 ,
                        else take the max possible*/
                    ll inter =0 , max =0;
                    for(ll i =0 ; i <num ; i++)
                    {
                        inter += arr[i];
                        max = maxm( max, inter);
                        if(inter <=0 ) inter =0;
                    }
                    show(max);
                }   
            }
        }
    }
    return 0;
}

