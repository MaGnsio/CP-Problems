//https://codeforces.com/gym/102892/problem/2
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
    ll n, k, cnt = 0;
    cin >> n >> k;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (ll i = 0; i < n; ++i)
    {
        ll ma = a[i], mi = a[i];
        for (ll j = i; j < n; ++j)
        {
            ma = max (ma, a[j]);
            mi = min (mi, a[j]);
            if (ma - mi == k) cnt++;
        }
    }
    cout << cnt;
}

