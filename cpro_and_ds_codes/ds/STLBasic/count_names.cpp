/* 
UNORDERED_MAP

Given a stream of inputs
i str - str has occured in the stream. 
g str - get the number of times it occured till now.

NOTE:
1. 
MAP, SET -> Balanced BST
UNORDERED_MAP, UNORDERED_SET -> Hash table
explore all of them.

2. 
use this if the compiler gives unordered_map error.
g++ --std=c++11 count_names.cpp
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	char c;
	string tmp;
	unordered_map<string, int> frequency;
	while(1)
	{
		cin>>c;
		if(c == 'i')
		{
			cin>>tmp;

			//string already occured before.
			if( frequency.find(tmp) != frequency.end() )
				frequency[tmp]++;
			else
				frequency.insert(make_pair(tmp, 1));
		}
		else if(c == 'g')
		{
			cin>>tmp;

			//string already occured before.
			if( frequency.find(tmp) != frequency.end() )
				cout<<"string: "<<tmp<<"\tfrequency: "<<frequency[tmp]<<endl;
			else
				cout<<"string did not occur in the stream."<<endl;	
		}
		else
			break;
	}
	return 0;
}