#include<stdio.h>

char string[100];
int n;

void swap( char arr[], int i , int j)
{
	char temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return;
}

void print( int current)
{
	static int number = 0;
	if( current == n-1 )
	{
		printf("number : %d %s\n" ,number++,  string);
		return;
	}
	for(int i = current ; i<n ; i++)
	{
		swap( string , current , i);
		print(current+1);
		swap(string , current , i);
	}
	return;
}


int main()
{
	scanf("%d" , &n);
	scanf("%s", string);
	print(0);
	return 0;
}
