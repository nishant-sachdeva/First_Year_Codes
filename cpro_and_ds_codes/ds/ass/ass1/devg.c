#include<stdio.h>

#define ll long long int
#define get(n) ll n; if(scanf("%lld", &n))
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
	get(test);
	while(test--)
	{
		int paper_x[100005], paper_y[100005];
		get(n);
		for (int i = 1; i <= n; ++i)
		{
			get(a) ;  get(b);
			paper_x[i] = a;
			paper_y[i] = b;
	    }
		int intern_x[100005], intern_y[100005];
		get(m);
		for (int i = 1; i <= m; ++i)
		{
			get(a);
			get(b);
			intern_x[i] = a;
			intern_y[i] = b;
		}
		mergesort(paper_x, paper_y, 1, n);
		mergesort(intern_x, intern_y, 1, m);

		/*for (int i = 1; i <= n; ++i)
		{
			printf("%d %d\n",paper_x[i], paper_y[i]);
		}*/

		int paper_start_latest = paper_x[n];
		int intern_start_latest = intern_x[m];

		mergesort(paper_y, paper_x, 1, n);
		mergesort(intern_y, intern_x, 1, m);

		int paper_khatam_earliest = paper_y[1];
		int intern_khatam_earliest = intern_y[1];

		//printf("intern_start_latest : %d  paper_khatam_earliest: %d\n" ,  intern_start_latest, paper_khatam_earliest);
		//printf("paper_start_latest: %d  intern_khatam_earliest: %d\n" ,paper_start_latest, intern_khatam_earliest);

		int diff_1 = intern_start_latest - paper_khatam_earliest;
		int diff_2 = paper_start_latest - intern_khatam_earliest;

		int ans = diff_1 > diff_2?diff_1:diff_2;

		if(ans > 0)
			printf("%d\n", ans );
		else
			printf("0\n");
	}
	

	return 0;
}