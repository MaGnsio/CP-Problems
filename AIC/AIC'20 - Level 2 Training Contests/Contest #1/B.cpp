//https://vjudge.net/contest/414669#problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll n, m;
ll a[100001], b[100001];

bool chk (ll mid)
{
    ll x = 0;
    for (ll i = 0; i < n; ++i)
    {
        if (x > m) return false;
        if (a[i] < mid) x += (mid - a[i]) * b[i];
    }
    return x <= m;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll l = LLONG_MAX, r = 0, ans;
        cin >> n >> m;
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i] >> b[i];
            l = min (l, a[i]);
            r = max (r, a[i] + (m / b[i]));
        }
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (chk (mid)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        cout << ans << "\n";
    }
}

