#include<stdio.h>


#define geti(n) float n; scanf("%f", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int main()
{
    geti(test);
    while(test--)
    {
        geti(a1); geti(a2); geti(b1) ; geti(b2);    
        char c[3] ; scanf("%s" , c);
        if( c[0] == 'A') printf("%.2f %.2f\n", a1+b1,a2+b2);
        else if( c[0] == 'S') printf("%.2f %.2f\n", a1-b1 , a2-b2);
        else if( c[0] == 'M') printf("%.2f %.2f\n", a1*b1 - a2*b2, a1*b2 + a2*b1);
        else if(c[0] == 'D')printf("%.2f %.2f\n", (a1*b1 + a2*b2)/(a2*a2+ b2*b2) , (-a1*b2 + a2*b1)/(a2*a2+ b2*b2) );
    }

    return 0;
}

