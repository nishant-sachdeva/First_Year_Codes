#include<stdio.h>


#define get(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int main()
{
    get(n); get(m); get(p);
    int arr1[n][m];
    int arr2[m][p];

    for(int i = 0 ; i<n ; i++)
        for( int j =0 ; j<m ; j++)
            scanf("%d", &arr1[i][j] );
    for( int i =0; i<m ; i++)
        for(int j=0 ; j<p ; j++)
            scanf("%d", &arr2[i][j] );
    int ans[n][p];
    for( int i =0; i<n ; i++)                                                   
        for(int j=0 ; j<p ; j++)
            ans[i][j] =0;

    for(int i =0 ; i<n ; i++)
        for(int j =0 ; j<m ;j++)
            for(int k = 0 ; k<m ; k++)
                ans[i][j] += arr1[i][k] * arr2[k][j] ;

    for( int i =0; i<m ; i++)                                                   
        for(int j=0 ; j<p ; j++)
            printf("%d", ans[i][j] );


    return 0;
}

