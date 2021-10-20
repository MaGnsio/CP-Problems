//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/Q
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
    ll n, r, s = 0, ans = 0;
    cin >> n >> r;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    while (s < n)
    {
        ll e = -1;
        for (ll i = max (0ll, s - r + 1); i < min (n, s + r); ++i) if (a[i]) e = i;
        if (e == -1)
        {
            cout << -1;
            return 0;
        }
        s = e + r, ans++;
    }
    cout << ans;
}

