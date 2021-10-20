//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/N
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
    ll n, t;
    cin >> n >> t;
    ll a[n], b[n];
    for (auto& elem : a) cin >> elem;
    b[0] = a[0];
    for (ll i = 1; i < n; ++i) b[i] = a[i] + b[i - 1];
    ll l = 0, r = 0, ans = 0;
    while (r < n)
    {
        while (b[r] - (l ? b[l - 1] : 0) <= t && r < n) r++;
        if (b[r] - (l ? b[l - 1] : 0) > t && l <= r) l++, ans = max (ans, r - l + 1);
    }
    cout << ans;
}

