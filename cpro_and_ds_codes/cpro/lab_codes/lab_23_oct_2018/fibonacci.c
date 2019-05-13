#include<stdio.h>

int fibo(int n)
{
    if( n == 0) return 0;
    if( n == 1) return 1;
    return fibo(n-1) + fibo( n-2);
}

int main()
{
    int arr[1000]= {-1};
    arr[0] =0;
    arr[1] =1;
    int n;
    scanf("%d", &n);
    int ans =0;
    /*ans = fibo(n);*/
    if( arr[n] != -1)
    {
        for( int i = 2 ; i<= n; i++)
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
    }
    printf("%d\n",arr[n]);
    return 0;
}
