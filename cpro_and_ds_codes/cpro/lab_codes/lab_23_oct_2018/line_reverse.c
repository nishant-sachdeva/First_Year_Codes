#include<stdio.h>
#include<string.h>


char arr[10005];

void line( int n)
{
    int i;
    for(i= n-1; i>=0;  i--)
    {
       // printf("hi\n");
        if( arr[i] == 32 || i == 0)
        {
            if(! i==0)printf("%s ", &arr[i+1]);
            else { printf("%s ", &arr[i]);}
            arr[i] = '\0'; 
            break;
        }
    }
   if( i>0) {  line(i);}
    return ;
}


    int main()
    {
        int n;
        scanf("%[^\n]s", arr);
        int size = (strlen(arr) -1);
        line(size);
        printf("\n");
        return 0;
    }
