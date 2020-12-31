//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/O
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
    pair<ll, ll> p[n];
    vector<ll> v(n);
    for (auto& elem : p) cin >> elem.F >> elem.S;
    sort (p, p + n);
    v[0] = p[0].S;
    for (ll i = 1; i < n; ++i) v[i] = p[i].S + v[i - 1];
    for (ll i = 0; i < n; ++i)
    {
        ll l = i, r = n - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (p[mid].F - p[i].F < m) l = mid + 1, ans = max (ans, v[mid] - (i ? v[i - 1] : 0));
            else r = mid - 1;
        }
    }
    cout << ans;
}

