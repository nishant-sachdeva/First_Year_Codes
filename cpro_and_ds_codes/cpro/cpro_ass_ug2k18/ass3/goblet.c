#include<stdio.h>

#define ll long long int
#define get(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int coor[110][110] = {0};

int mod (int x)
{
    return x>0?x:-x;
}

int main()
{
    get(n);
    get(q);
    int count = 0;
    while(q--)
    {
        char arr[10];
        scanf("%s", arr);
        get(a); get(b);
        if(arr[0] == 'P')
        {
            count++;
            coor[a][b] = 1;
        }
        else if( arr[0] = 'F')
        {
            if( count == 0) printf("-1 -1\n");
            else{
                int ans = 2*n;
                int left=n, right=n;

                for(int i = 1 ; i <= n ; i++)
                {
                    for(int j = 1 ; j<=n ; j++)
                    {
                        if( coor[i][j] == 1)
                        {
                            int dis = mod(a-i) + mod(b-j);
                            if( dis ==  ans)
                            {
                                if( i < left )
                                {
                                    left = i;
                                    right = j;
                                }
                                else if( i == left)
                                {
                                    if( j < right)
                                        right = j;
                                }
                    
                            }
                            else if( dis < ans)
                            {
                                left = i;
                                right = j;
                                ans = dis;
                            }
                        }
                    }
                }
                printf("%d %d\n", left, right);
            }
        }

    }

    return 0;
}

