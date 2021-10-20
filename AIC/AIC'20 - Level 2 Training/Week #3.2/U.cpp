//https://vjudge.net/contest/419723#problem/T
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll seconds (ll k, ll n, ll a[])
{
    ll res = 0;
    for (ll i = 0; i < n; ++i)
    {
        res += min (a[i] % k, k - a[i] % k);
    }
    return res;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, ans = LLONG_MAX;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (ll i = 1; i < n; ++i) a[i] += a[i - 1];
    if (a[n - 1] == 1) return cout << -1, 0;
    ll peak = a[n - 1], k = 2;
    while (k * k <= peak)
    {
        if (peak % k == 0)
        {
            ans = min (ans, seconds (k, n, a));
            while (peak % k == 0) peak /= k;
        }
        k++;
    }
    if (peak > 1) ans = min (ans, seconds (peak, n, a));
    cout << ans;
}

