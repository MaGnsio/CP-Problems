//https://codeforces.com/group/aDFQm4ed6d/contest/288718/problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, t, c, cnt = 0;
    cin >> n >> t >> c;
    vector<ll> v(n), s;
    for (auto& x : v) cin >> x;
    for (ll i = 0, l = -1; i < n; ++i)
    {
        if (v[i] > t)
        {
            s.push_back (max (0ll, i - l - 1));
            l = i;
        }
        if (i == n - 1) s.push_back (max (0ll, i - l));
    }
    for (auto& x : s) cnt += max (0ll, x - c + 1);
    cout << cnt;
}

