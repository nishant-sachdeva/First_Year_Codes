#include<stdio.h>

int len(char *a , char c)
{
	if( *a == c)
		return 0;
	return 1 + len(a+1, c);
}

int main()
{
	char arr[1000], c;
	scanf("%s", arr);
	scanf(" %c", &c);
	int length = len( arr , c);
	printf("%d \n", length);
	return 0;
}
