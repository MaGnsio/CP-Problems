//https://codeforces.com/group/nVgev28wQI/contest/308101/problem/I
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, x, y, t = 0;
    cin >> n;
    map<ll, ll> m;
    for (ll i = 0; i < n; ++i)
    {
        cin >> x >> y;
        m[x] += y;
    }
    auto it = m.begin ();
    t += (it -> F + it -> S), it++;
    for (; it != m.end (); ++it)
    {
       t = max (t, it -> F);
       t += it -> S;
    }
    cout << t << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

