#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int main()
{
    int k=0 ,count= 0; geti(n); int arr[n];
    loop(0,n) { geti(ni) ; arr[i] = ni;}
    for(int i =0 ; i <= n-2 ; i++) 
    {
        if(arr[i] != arr[i+1]){ count++;  arr[k++] =  arr[i];}
        else 
        {
            int temp = arr[i];
            while(arr[i] == temp)
            {i += 1; }
            i--;
        }
    }
    if(arr[n-1] != arr[n-2]) arr[k++] = arr[n-1];
    loop(0,n) { printf("%d", arr[i]); }
    return 0;
}

