#include<stdio.h>

#define pr 0.0001

float mod( float a)
{
	if( a > 0 ) return a;
	return -a;
}

int main(void)
{
	float n;
	scanf("%f", &n);
	float ans = 2;
	while( mod( ans*ans - n) > pr )
	{
		ans = 0.5* ( ans + n/ans  );
	}
	printf("%f\n", ans);
	return 0;
}
	
		
