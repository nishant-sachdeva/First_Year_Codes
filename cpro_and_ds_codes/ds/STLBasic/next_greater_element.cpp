/*
STACK
code to print the immediate next(to its right) greater element of each number in the given array.
if no such number exists print -1.
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    
    long long int n;
    cin>>n;
    vector<long long int> arr(n), nge(n);

    for(int j=0;j<n;j++)
        cin>>arr[j];
        
    stack<long long int> st;

    for(int j=0;j<arr.size();j++)
    {
        //popping the stack till the current element is nge of top.
        while(!st.empty() && arr[st.top()] < arr[j])
        {
            nge[st.top()] = arr[j];
            st.pop();
        }
        st.push(j);
    }
    
    //the remaining elements in the stack have no greater elements to right.
    while(!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }


    for(int j=0;j<n;j++)
        cout<<nge[j]<<" ";
    cout<<endl;
    return 0;
}