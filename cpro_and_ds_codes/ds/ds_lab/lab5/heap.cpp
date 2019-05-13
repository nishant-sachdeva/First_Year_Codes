#include<bits/stdc++.h>


#define ll long long int
#define sz(a) ll(a.size())
#define get(a) ll a ; cin >> a
#define vec(A) vector <A>
#define pb push_back
#define full(p) p.begin(),p.end()
#define show(a) cout << a <<'\n'
#define eb emplace_back
#define nl '\n'


using namespace std;

template<typename T> T maxm(T x,T y) {return (x>y)?x:y;}
template<typename T> T mod(T x) {return (x>0)?x:-x;}


int heap[10000] = {0};

void swap(int a, int b)
{
	int temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
	return;
}

void insert(int a, int n)
{
	// n is the current index where stuff has to
	// be stored, n -1 is the current size;
	//it;s a max heap, so the root
	// is biggeer= than ir's kids
	heap[n] = a;
	int l = n;
	while(a > heap[l/2])
	{
		// i.e the kid is bigger than it'a parent
		swap(l, l/2);
		l >>= 1; // l = l/2;
	}
	n++; // the size has increased;
	// so we found a proper place for the thing 
	// so, all is well
	return;

}


/*void delete(int index)
{
	// we are looking to delete the guy at the 
	// given index in a max heap;
	// max index currently is n;
	heap[index] = heap[n];
	// element deleted, now , place it properly
	 
}*/

/*void delete(int index, int size)
{
	heap[index] = heap[size];
	for(int i = index ; 2*i<=size ;)
	{
		// swap heap[1] with the min of the kids,unless they are bigger than the element in question
		int ele = heap[i];
		if(2*i+1 <= size)
		{ // this is the guy I mean to place down
			if(ele < heap[2*i] && ele < heap[2*i+1])
				break;
		// now we know that this is not the min

			if(heap[2*i] < heap[2*i+1])
			{
				swap(2*i , i);
				i <<=1;
			}
			else
			{
				swap(2*i+1, i);
				i <<=1;
				i++;
			}
		}
		else // means that the guy is midway, the second child is not part of the heap
		{
			if(ele < heap[2*i])
			{
				swap(i, 2*i);
				i <<= 1 ;
			}
			else
				break;
		}
	}
	return ans;
}

int extract_min(int size)
{
	// note if size is n, then final index will be n itself
	int ans = heap[1]; // this'll be returned
	heap[1] = heap[size];
	// now we'll sift down
	for(int i = 1 ; 2*i<=size ;)
	{
		// swap heap[1] with the min of the kids,unless they are bigger than the element in question
		int ele = heap[i];
		if(2*i+1 <= size)
		{ // this is the guy I mean to place down
			if(ele < heap[2*i] && ele < heap[2*i+1])
				break;
		// now we know that this is not the min

			if(heap[2*i] < heap[2*i+1])
			{
				swap(2*i , i);
				i <<=1;
			}
			else
			{
				swap(2*i+1, i);
				i <<=1;
				i++;
			}
		}
		else // means that the guy is midway, the second child is not part of the heap
		{
			if(ele < heap[2*i])
			{
				swap(i, 2*i);
				i <<= 1 ;
			}
			else
				break;
		}
	}
	return ans;
}

void insert(int num, int end)
{
	// I am making a min heap
	heap[end] = num;
	while(end > 0 && (heap[end/2] > heap[end]))
	{
		swap(end, end/2);
		end = end/2;
	}
	return;
}

*/


int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////
 	get(n);
 	int arr[2000];
 	for (int i = 0; i < n; ++i)
 	{
 	   	get(ni);
 	   	arr[i] = ni;
 	}
 	for (int i = 0; i < n; ++i)
 	{
 		insert(arr[i] , i+1);
 	}
 	for (int i = 1; i < n+1; ++i)
 	{
 		cout << heap[i] << " ";
 	}
 	cout << endl;	
 	int s = n;
 	for (int i = 1; i <= n; ++i)
 	{
 		cout << extract_min(s) << nl;
 		s--;
 	}
    return 0;
}