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

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
    ////////////////////////////////
	get(n);
	std::vector<string> v;
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		v.pb(s);
	}    
	sort(full(v));
	for(auto i : v)
		cout << i << endl;
    return 0;
}