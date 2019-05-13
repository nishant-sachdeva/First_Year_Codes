#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

/*int maxm( int a, int b)
{
    if( a>b) return a;
    return b;
}*/

int main()
{
    char arr[1000006];
    geti(test);
    while(test--)
    {
        geti(n); geti(m);
        scanf("%s", arr);
        int flag1=0, flag2=0, len=0, maxlen= 0, nod=0;
        int j =0; int  i=0;
        for(; i<n ; i++)
        {
            if(arr[i] == 'd') nod++;
            //len = i-j+1;
            //maxlen = maxm( len , maxlen);
            //printf("%d" , maxlen);
            if (nod == m+1)
            {
                //len =  i - j;
                //show(len);
                //maxlen = maxm( len , maxlen);
                //show(maxlen);
                for(; j<n ; j++)
                {
                    if(arr[j] == 'd')
                    {
                        nod--;j++; break;
                    }
                }
            }
            len = i - j + 1;
            maxlen = maxlen > len? maxlen:len ; //maxm(len , maxlen);
        }
        show(maxlen);
    }

    return 0;
}

