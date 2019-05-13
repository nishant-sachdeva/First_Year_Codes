#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int mod (int a)
{
    if(a >= 0) return a;
    return -a ;

}

int isspecial( int a)
{
    //printf("%d\n", a);
    int even =0 , odd =0;
    while( a > 0 )
    {
        if( (a%10) %2 == 0) even++;
        else odd++;
        a /= 10;
    }
    //printf("%d %d \n", odd, even);
    if( mod(even - odd) <= 1) return 1;
    return 0;
}
int main()
{
    int l ,r;
    scanf("%d%d", &l, &r); int count =0;
    for(int i = l ; i <= r ; i++)
    {
        if( isspecial(i)) { count ++ ;}
    }
    printf("%d\n", count);
    
    return 0;
}

