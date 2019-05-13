#include<stdio.h>

#define int long long int
#define get(n) int n; if(scanf("%lld", &n))
#define gets(n) char n ; if(scanf("%c", &n))
#define show(n) printf("%lld\n", n)
#define shows(n) printf("%c\n",n)
#define loop(a,b) for( int i=a ; i<b ; i++)
#define eloop(a,b) for(int i=a ; i<=b ; i++)

void merge(int arr[] , int arr2[], int left, int mid, int right)
{
		int n1 = mid-left + 1;
		int n2 = right-mid;
		int l[n1], l2[n1],r2[n2] , r[n2];
		for(int i = 0 ; i<n1 ;i++)
		{
				l[i] = arr[left+i];
				l2[i]= arr2[left+i];
		}
		for(int i = 0 ; i<n2 ; i++)
		{
				r[i] = arr[mid+1+i];
				r2[i] = arr2[mid+1+i];
		}
		int k = left, i=0, j=0;
		while(i<n1 && j<n2)
		{
				if(l[i] <= r[j])
				{
						arr[k] = l[i];
						arr2[k++] = l2[i++];
				}
				else if(r[j] < l[i])
				{
						arr[k] = r[j];
						arr2[k++] = r2[j++];
				}
		}
		while(i<n1)
		{
				arr[k] = l[i];
				arr2[k++] = l2[i++];
		}
		while(j<n2)
		{
				arr[k] = r[j];
				arr2[k++] = r2[j++];
		}
		return;
}

void mergesort( int arr[], int arr2[], int left, int right)
{
		if(left < right)
		{
				int mid = (left + right)/2;
				mergesort(arr, arr2 , left , mid);
				mergesort(arr, arr2 , mid+1, right);
				merge(arr, arr2,  left , mid, right);
		}
		return ;
}


int count = 0;

int find(int arr[] , int left , int mid , int right)
{
	int c = 0;
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
		else if(l[i] > r[j])
		{
			c += s1 - i;
			arr[k++] = r[j++];
		}
	}
	while(i < s1) { arr[k++] = l[i++];}
	while(j < s2) { arr[k++] = r[j++];}
	return c;
}


void calc(int arr[], int left , int right)
{
	if(left < right)
	{
		int mid = (left + right)/2;
		calc(arr, left, mid);
		calc(arr,  mid+1 , right);
		count += find(arr ,left, mid, right);
	}
	return;
}

int p[1000006];
int q[1000006];

int main()
{
	get(test);
	while(test--)
	{
		count =0;
		get(n);
		for (int i = 0; i < n; ++i)
		{
			get(pi);
			get(qi);
			p[i] = pi;
			q[i] = qi;
		}
		mergesort(p, q, 0, n-1);
		/*for(int i =0 ; i<n; i++)
		{
			printf("%lld %lld\n",p[i], q[i] );
		}*/
		calc(q , 0, n-1);
		show(count);
	}
	

	return 0;
}
