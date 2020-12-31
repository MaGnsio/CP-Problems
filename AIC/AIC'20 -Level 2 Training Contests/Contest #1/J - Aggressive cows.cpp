//https://vjudge.net/contest/414669#problem/J
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (ll n, ll m, ll c, ll a[])
{
    ll y = 1, cur = a[0];
    for (ll i = 1; i < n; ++i)
    {
        if (a[i] - cur >= m) y++, cur = a[i];
        if (y >= c) return true;
    }
    return y >= c;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t, n, c;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        ll a[n];
        for (auto& elem : a) cin >> elem;
        sort (a, a + n);
        ll l = 0, r = 1000000000, mid, ans;
        while (l <= r)
        {
            mid = r + (l - r) / 2;
            if (chk (n, mid, c, a)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        cout << ans << "\n";
    }
}

