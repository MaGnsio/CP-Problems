//https://vjudge.net/contest/421809#problem/J
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, ans = LLONG_MAX;
        cin >> n >> k;
        ll a[n];
        for (auto& x : a) cin >> x;
        sort (a, a + n);
        for (ll i = 0, j = k - 1; j < n; ++j, ++i) ans = min (ans, a[j] - a[i]);
        cout << ans << "\n";
    }
}

