//https://vjudge.net/contest/419722#problem/J
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
    ll n, ans = 0;
    cin >> n;
    vector<ll> cnt (1'000'001, 0);
    cnt[0] = 1;
    for (ll i = 0; i < n; ++i)
    {
        ll x;
        vector<ll> v;
        cin >> x;
        for (ll j = 1; j * j <= x; ++j)
        {
            if (x % j == 0)
            {
                v.push_back (j);
                if (j * j != x) v.push_back (x / j);
            }
        }
        sort (v.begin (), v.end (), greater<ll> ());
        for (auto& k : v) cnt[k] += cnt[k - 1], cnt[k] %= mod;
    }
    for (ll i = 1; i <= n; ++i) ans = ((ans % mod) + (cnt[i] % mod)) % mod;
    cout << ans;
}

