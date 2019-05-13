/*
HEAP
https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, tmp, ans = 0;
    cin>>n;
    
    //getting a min heap.
    priority_queue<long long int, vector<long long int>, greater<long long int>> min_hp;
    
    for(int j=0;j<n;j++)
    {
        cin>>tmp;
        min_hp.push(tmp);
    }
    
    //get the smallest 2 ropes, unite them and put back.
    while(min_hp.size()>=2)
    {
        tmp = min_hp.top();
        min_hp.pop();
        tmp += min_hp.top();
        min_hp.pop();
        ans += tmp;
        min_hp.push(tmp);
    }
    
    //all ropes unified.
    if(min_hp.size()==1)
        cout<<ans<<endl;
    else
        cout<<"Error"<<endl;
    return 0;
}