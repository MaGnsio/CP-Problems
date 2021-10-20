//https://vjudge.net/contest/418569#problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	ll n, q;
	cin >> n >> q;
    vector<string> v(n);
    for (auto& X : v) cin >> X;
	sort (v.begin (), v.end ());
	while(q--)
	{
        string s;
		cin >> s;
		ll k = upper_bound (v.begin (), v.end (), s) - v.begin ();
        cout << k << "\n";
	}
}

