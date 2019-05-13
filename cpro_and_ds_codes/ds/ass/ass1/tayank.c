#include<stdio.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)


int merge(int arr[] , int left , int mid , int right)
{
	int inver = 0;
	int i, j, k;
	int s1 = mid - left + 1;
	int s2 = right - mid;
	int l[s1] , r[s2];
	for(int i=0 ; i<s1; i++) { l[i] = arr[left + i];}
	for(int i=0 ; i<s2 ; i++ ) { r[i] = arr[mid +1+ i];}
	i=0 ; j=0 ; k = left;
	while(i < s1 && j < s2)
	{
		if(l[i] <= r[j])
		{
			arr[k++] = l[i++];
		}
		else
		{
			inver += mid-i+1;
			arr[k++] = r[j++];
		}
	}
	while(i < s1) { arr[k++] = l[i++];}
	while(j < s2) { arr[k++] = r[j++];}
	return  inver;
}


int merge_sort(int arr[], int left , int right)
{
	int one=0, two=0,three=0;
	if(left < right)
	{
		int mid = (left + right)/2;
		one =  merge_sort(arr, left, mid);
		two = merge_sort(arr,  mid+1 , right);
		three = merge(arr ,left, mid, right);
	}
	//printf("%d %d  %d\n", one, two, three );
	return (one + two + three);
}

int main()
{
	get(t);
	while(t--)
	{
		int arr[30005];
		get(n);
		for (int i = 0; i < n; ++i)
		{
			get(ni);
			arr[i] = ni;
		}
		int inversions = merge_sort(arr, 0, n-1);
		//printf("%d\n",  inversions);
		if(inversions%2 == 1)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}