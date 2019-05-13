#include<stdio.h>
#include<string.h>

int main()
{
	char arr1[100005] , arr2[100005];
	scanf("%s %s", arr1 , arr2);

	int len1 = strlen(arr1); 
	int len2 = strlen(arr2);
	int check =1 ;
	for(int i=0 ; i<len1 ; i++)
	{
		check = 1;
		for(int j = 0 ;j <len2 && i+j <= len1 ; j++)
		{
		//	printf(" i =%d   j =%d   i+j =%d  \n" ,i ,j , i+j);
			if( arr1[i+j] != arr2[j])
			{ check = 0 ; break;}
			if( j == len2-1 && i+j >= len1 && check == 1) { check =0;}

		}
		if(check == 1) { printf("YES\n"); break; }
	}
	if(check == 0) printf("NO\n");
	return 0;
}
