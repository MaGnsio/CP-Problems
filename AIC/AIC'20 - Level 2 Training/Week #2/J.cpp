//https://vjudge.net/contest/417978#problem/J
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
    ll n, k;
    queue<ll> q;
    map<ll, ll> m;
    cin >> n >> k;
    for (ll i = 0; i <= 30; ++i)
    {
        if(n & (1 << i))
		{
			if (i > 0) q.push (1 << i);
			m[1 << i]++;
		}
    }
    if (m.size () > k) return cout << "NO", 0;
    ll cnt = m.size ();
    while (cnt < k && !q.empty ())
    {
    	ll x = q.front();
		q.pop();
		m[x]--;
		m[x / 2] += 2;
		if(x / 2 > 1)
		{
			q.push(x / 2);
			q.push(x / 2);
		}
		cnt++;
    }
    if (cnt < k) return cout << "NO", 0;
    cout << "YES\n";
    for (auto& X : m) for (ll i = 0; i < X.S; ++i) cout << X.F << " ";
}

