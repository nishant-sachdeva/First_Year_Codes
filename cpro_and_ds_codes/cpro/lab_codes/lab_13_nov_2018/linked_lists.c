#include<stdio.h>


typedef struct point {
	int key;
	struct point *pointer;
}point;


int main()
{
	point head;
	head.key = 0;
	point prev = head;
	for(int i =1; i<9 ; i++)
	{
		point temp;
		temp.key = i;
		prev.pointer = &temp;
		prev = temp;
	}

	return 0;
}	
