#include<stdio.h>


#define geti(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)
#define size 1137


int arr[size];
//init globally, so all the elements are at 0


int main()
{
    geti(test);
    while(test--)
    {
        loop(0,1136) { arr[i] = 0;}

        geti(n);
        arr[1136] = 1;
        for(int i =1 ; i<= n; i++)
        {
            int carry =0; // this is the init carry
            for(int  j  = 1136 ; j>=0 ; j--)
            {
                int  temp = i*arr[j] + carry;
                arr[j] = temp%10;
                carry = temp/10;
            }
        }
        // now we  have  the factorial, we'll print it now
        int i=0;
        for(i =0 ; i<= 1136 ; i++)
            if(arr[i] != 0) { break; }
        for(int j = i; j<= 1136 ; j++)
        { printf("%d", arr[j] ); }
        printf("\n");
    }
    return 0;
}
