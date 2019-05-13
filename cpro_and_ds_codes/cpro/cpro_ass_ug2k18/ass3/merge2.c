#include<stdio.h>

#define int  long long int
#define get(a) int a; scanf("%lld", &a);
#define show(a) printf("%lld", &a);


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
				if(l[i] < r[j])
				{
						arr[k] = l[i];
						arr2[k++] = l2[i++];
				}
				else if(r[j] < l[i])
				{
						arr[k] = r[j];
						arr2[k++] = r2[j++];
				}
				else if(l[i] == r[j])
				{
					if(l2[i] < r2[j])
					{
						arr[k] = l[i];
						arr2[k++] = l2[i++];
					}
					else
					{
						arr[k] = r[j];
						arr2[k++] = r2[j++];
					}
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

int main()
{
		get(n);
		int arr[100], arr2[100];
		for(int i = 0 ; i<n ; i++)
		{
				get(ni); get(nii);
				arr[i] = ni;
				arr2[i] = nii;
		}
		mergesort(arr, arr2, 0, n-1);
		for(int i = 0 ; i<n ; i++)
				printf("%lld %lld\n", arr[i], arr2[i]);
		return 0;

}
