//https://vjudge.net/contest/418569#problem/D
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
    ll n, q, res_1 = 0;
    cin >> n;
    ll a[n], s[n];
    for (auto& X : a) cin >> X;
    sort(a, a + n, greater<ll> ());
    s[0] = a[0];
    for (ll i = 1; i < n; ++i) s[i] = s[i - 1] + a[i];
    for (ll i = 1; i < n; ++i) res_1 += a[i] * i;
    cin >> q; 
    for (ll i = 0; i < q; ++i)
    {
        ll k;
        cin >> k;
        if (k == 1)
        {
            cout << res_1 << " ";
            continue;
        }   
        ll res = 0, sz = 1;
        for (ll j = 1, t = 1; j < n; j += sz, t++)
        { 
            sz *= k;
            res += (s[min (j + sz - 1, n - 1)] - (j ? s[j - 1] : 0)) * t;
        }
        cout << res << " ";
    }
}
