#include<stdio.h>


int max ( int a, int b)
{
    if(a > b) return a;
    return b;
}

int main()
{
    int test; 
    scanf("%d", &test);
    while(test--)
    {
        int s1, s2;
        scanf("%d%d", &s1, &s2);

        char str1[20] , str2[20];
        scanf("%s %s", str1 ,  str2);
        {
            int num1=0, num2 = 0, tot = 0;
            for(int  i = s1-1 , pow =1  ; i>=0 ; i-- , pow*=2)
            {
               num1 += (str1[i] - '0') * pow; 
                //num2 +=(str2[i] - '0') * pow;
                tot += pow;
            //printf("%d\n", num1);
            }
            int tot1 = 0;
            //printf("%d\n", num1);
            for( int i = s2-1 , pow = 1 ; i>=0 ; i--, pow*= 2)
            {
               num2 += (str2[i] - '0') * pow; 

              //printf("%d\n", num2);

                tot1 += pow;
            }
            //printf("%d\n", num2);
            // for doing sign extension , i'll do the following
            //if ( s1 == s2) tot = ( tot > tot1 ? tot : tot1);
            //else { tot = (1 << (max(s1 , s2)) )  -1; }
            if( num2 == (tot  - num1)) { printf("ONE\n"); }
            //else if (num1 == 0 && num2 == 1 << s2) printf("TWO\n");
            else if( num2 == (tot - num1 +1)) { printf("TWO\n");}
            else printf("LOL\n");
        }
    }
    return 0;
}

