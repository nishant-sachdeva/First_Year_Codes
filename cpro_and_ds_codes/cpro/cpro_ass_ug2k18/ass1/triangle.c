#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1 ; i<=n ; i++) printf("o "); printf("\n");    
    if( n != 1)
    {
        int space = 1;
        for( int num = n/2  ; num > 1 ; num-- , space ++)
        {
            for(int i = 1 ; i<=space ; i++) printf(" ");

            for(int i = 1 ; i<= num ; i++)
            { if( i == 1|| i == num) printf("o "); else printf("  "); }

            for(int i = 1 ; i< 2*space - 1 ; i++) printf(" ");

            for(int i = 1 ; i<= num ; i++) 
            { if( i == 1 || i == num) printf("o "); else printf("  "); }
            printf("\n");
        }
        for(int i = 1 ; i<=space ; i++) printf(" ");
        for(int i = 1 ; i<=n/2 + 1 ; i++) printf("o "); printf("\n");
        space++;
        for(int num = n/2  ; num >=1 ; space++, num--)
        {
            for(int i = 1 ; i<=space ; i++) printf(" ");
            for(int i = 1 ; i<=num ; i++)
            { if( i ==1 || i == num) printf("o "); else printf("  "); } 
            printf("\n");
        }
    }
    return 0;
}

