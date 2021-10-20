//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/T
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
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto& elem : a) cin >> elem;
    a.resize (unique (a.begin (), a.end ()) - a.begin ());
    for (auto& elem : b) cin >> elem;
    b.resize (unique (b.begin (), b.end ()) - b.begin ());
    for (ll i = 0, j = 0; i < a.size (); ++i)
    {
        ll prev = abs (a[i] - b[j]);
        while (j + 1 < b.size () && abs (a[i] - b[j + 1]) < prev) prev = abs (a[i] - b[j + 1]), j++;
        ans = max (ans, abs (a[i] - b[j]));
    }
    cout << ans;
}

