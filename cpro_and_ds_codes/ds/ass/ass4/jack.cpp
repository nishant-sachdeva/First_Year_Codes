#include<bits/stdc++.h>


#define ll long long int
#define sz(a) ll(a.size())
#define get(a) int a ; cin >> a
#define vec(A) vector <A>
#define pb push_back
#define full(p) p.begin(),p.end()
#define show(a) cout << a <<'\n'
#define eb emplace_back
#define nl endl;


using namespace std;
ll retime[100005];
ll cost[100005];
ll n = 0;

template<typename T> T maxm(T x,T y) {return (x>y)?x:y;}
template<typename T> T mod(T x) {return (x>0)?x:-x;}

int brute_cost=0;

int find_time(int j)
{
	ll ans = brute_cost;
	ll walk = 0, bus = 0;
	for(int i = 1+j ; i<n ; i++)
	{
		walk += 1;
		walk+= retime[i+1];
	}
	// this is the time to walk
	bus += (j + retime[1+j]);
	// so now, we hve the costs, we can start the comaprisons and the loops
	for(int i = 1+j ; i<=n ; i++)
	{
		// cout << "walk: " << walk << " bus: " << bus << endl;
		ll time = walk + bus;
		ans = ans<time?ans:time;
		// cout <<  "ans becomes " << ans << endl;
		// ye toh hui calc, abi dekhteh hain, changes;
		bus =j + retime[i+1];
		walk -= retime[i+1];
		walk -= 1;
		walk += retime[i - j + 1];
		walk += 1;
	}
	// after this loop, I've got the time for that particular thing, 
	return ans;
}


int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	cout.precision(10);
	cout<<fixed;
	////////////////////////////////
	cin >> n;
	get(t);
	for (int i = 1; i <= n-1; ++i)
	{
		get(ni);
		cost[i] = ni;
	}
	for (int i = 2; i <= n-1; ++i)
	{
		get(ni);
		brute_cost += ni;
		retime[i] = ni;
	}
	retime[1] = 0;
	retime[n] = 0;
	brute_cost += n-1;
	ll final = 1e9;
	ll l = 1 , r = n;
	if(brute_cost <= t)
	{
		final = 0;
	}
	else{
		// ill try the brute force thing 
		for (int i = 1; i < n ; ++i)
		{
			int temp = find_time(i);
			if(temp <= t)
				final = final<i?final:i;
			/* code */
		}
	// while(l < r)
	// {
	// 	// cout << 1 << endl;
	// 	ll mid  = (l+r)/2;

	// 	ll temp = find_time(mid);
	// 	cout << "the cost of jump is " << mid << " and the time is " << temp << endl;
	// 	if(temp > t)
	// 		l = mid+1;
	// 	else
	// 	{
	// 		final = final < cost[mid]?final:cost[mid];
	// 		r = mid - 1;
	// 	}
	// }
	}
	cout << final << nl;

	return 0;
}
