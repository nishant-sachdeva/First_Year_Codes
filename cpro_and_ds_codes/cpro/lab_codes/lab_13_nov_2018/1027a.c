#include<stdio.h>

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n; 
		scanf("%d" , &n);
		char arr[100];
		scanf("%s", arr);
		int start=0, end = n-1;
		int check = 0;
		while(start < end)
		{
			int sl = (int)arr[start]-1;
			int sm = (int)arr[start]+1;
			int el = (int)arr[end]-1;
			int em = (int)arr[end]+1;
			//printf("for %c %d and  %d for %c  %d and %d\n", arr[start], sl, sm, arr[end], el, em);
			if( sl == el || sl == em || sm == el || sm == em){
				check = 0;
			}
			else
			{
				check = 1;
				break;
			}
			start++;
			end--;
		}
		if(check == 1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
