#include<stdio.h>
#include<string.h>

int main()
{
	char arr[15];
	scanf("%s", arr); int check = 0;
	int start =0 , end = (int) strlen(arr) -1; 
	while( start < end)
	{
		printf("%c %c\n", arr[start] , arr[end]);
		if( arr[start] != arr[end]) { check = 1; break; }
		start++; end--;
	}
	check == 1? printf("no\n"): printf("yes\n");
	return 0;
}



