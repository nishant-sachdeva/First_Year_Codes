#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int main()
{
    geti(n);
    int arr[n];  loop(0,n) { arr[i] =0 ;}
    scanf("%d" , &arr[0]);
    loop(1,n) { geti(ni); arr[i] = ni + arr[i-1];}
    //loop(0,n) { show(arr[i]); }
    //printf("enter queries\n");
    geti(queries);
    loop(0,queries) 
    {
        //printf("enter indices \n");
        geti(l); geti(r);
        show(arr[l]); show(arr[r]);
        if(l) { int ans = arr[r] - arr[l-1]; show(ans);}
        else { show(arr[r]); }
    }
    return 0;
}

