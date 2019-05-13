#include<stdio.h>

int gcd ( int n, int m)
{
    if(m == 0) return n;
    return gcd( m , n%m);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = gcd(n,m);
    printf("%d\n", ans);
    return 0;
}
