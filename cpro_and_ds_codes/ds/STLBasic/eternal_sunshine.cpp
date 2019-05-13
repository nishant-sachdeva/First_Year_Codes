/*
DEQUEUE
Assignment 2 question
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int n,k;
	cin>>n>>k;
	long long int arr[n], st[n];
	pair<long long int, long long int> temp[k];
	deque< pair<long long int, long long int> > dq;

	for(long long int j=0;j<n;j++)
	{
		cin>>arr[j];
		if(j>=1 && j<=k)
		{
			temp[j-1] = make_pair(arr[j], j);
			st[j] = arr[j]; 
		}
	}
	
	st[0] = arr[0];

	sort(temp, temp+k);
	for(long long int j=0;j<k;j++)
		dq.push_back(temp[j]);

	//0 handled separately and 1 to k are handled in initial sort.
	for(long long int j=k+1;j<n;j++)
	{
		while(!dq.empty() && dq.front().second< j-k)
			dq.pop_front();
		if(dq.empty())
		{
			cout<<"error in code/testcase.\n";
			return 0;
		}
		else
			st[j] = arr[j] + dq.front().first;

		while( !dq.empty() && dq.back().first>=st[j] )
			dq.pop_back();
		dq.push_back(make_pair(st[j], j));
	}
	
	cout<<st[n-1]+st[0]<<endl;
	return 0;
}