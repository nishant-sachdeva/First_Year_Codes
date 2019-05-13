#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int min( int a, int b)
{
    if(a <=  b) return a;
    return b;
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    char name1[100005], name2[100005];
    scanf("%s %s", name1, name2);
    for(int i = 0 ; i<n ; i++)
    {
        if(name1[i] >= 'A' && name1[i] <= 'Z')
            name1[i] += 32;
    }
    for(int i = 0 ; i<m ; i++)
        if(name2[i] >= 'A' && name2[i] <= 'Z')
            name2[i] += 32;
    //printf("%s %s\n", name1, name2);
    
    int check = 0;

    for( int i =0 ; i< min(n,m) ; i++)
    {
        if( name1[i] != name2[i] )
        { 
            check = 1;
            if( name1[i] < name2[i]) printf("1\n");
            else printf("2\n");
            break;
        }
    }
    if(check == 0)
    {
        if( n < m ) printf("1\n");
        else printf("2\n");
    }
    return 0;
}

