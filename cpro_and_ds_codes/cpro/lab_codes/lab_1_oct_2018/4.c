#include<stdio.h>


#define get(n) int n; scanf("%d", &n)
#define gets(n) char n ; scanf("%c", &n)
#define show(n) printf("%d\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

int  n, m;

void spiral ( int arr[n][m] , int row, int col)
{
	int left =0, top =0;
	while(top < row && left < col)
	{
		for (int i = left; i < col; i++)
		{
			printf("%d ",arr[top][i]);
		}
		top++;
		for(int i = top	 ; i< row ; i++)
		{
			printf("%d ",arr[i][col-1]);
		}
		col--;
		if( top < row )
		{
			for(int i = col -1 ; i>= left ; i-- )
			{	
				printf("%d " , arr[row-1][i]);
			}
			row--;
		}
		if(left < col)
		{
			for(int i = row -1; i>= top ; i--)
			{
				printf("%d " , arr[i][left]);
			}
			left++;
		}
	}
}

int main()
{
    scanf("%d %d", &n, &m); int arr[n][m];
    for(int i =0; i<n ; i++)
        for(int j =0 ; j< m ; j++)
        { scanf("%d", &arr[i][j]);}
    spiral ( arr,n , m);
    printf("\n");
    return 0;
}

