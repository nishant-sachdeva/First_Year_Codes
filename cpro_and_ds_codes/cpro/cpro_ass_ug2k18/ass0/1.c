#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
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
        geti(ai);
        int temp1 = ai-2 , temp2 = 1;
        while(1)
        {
            printf("READ %d\n" , temp1);
            char string[10]; scanf("%s", string);
            printf("READ %d\n" , temp2);
            char string2[10] ; scanf("%s" , string2);
            if(string[0] == 't') { printf("OUTPUT %d\n" ,temp1); break;}
            else if( string2[0] == 'f') { printf("OUTPUT %d\n", temp2-1); break;}
            else { temp1-- ; temp2++; }
        }
    }
    return 0;
}

