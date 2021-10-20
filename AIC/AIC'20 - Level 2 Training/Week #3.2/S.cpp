//https://vjudge.net/contest/419723#problem/S
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

vector<ll> v;

ll seconds (ll k)
{
    ll res = 0;
    for (ll i = 0; i < v.size (); i += k)
    {
        ll mid = v[(i + i + k - 1) / 2];
        for (ll j = i; j < i + k; ++j) res += abs (mid - v[j]);
    }
    return res;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, ans = LLONG_MAX;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1) v.push_back (i);
    }
    if (v.size () == 1) return cout << -1, 0;
    ll peak = v.size (), k = 2;
    while (k * k <= peak)
    {
        if (peak % k == 0)
        {
            ans = min (ans, seconds (k));
            while (peak % k == 0) peak /= k;
        }
        k++;
    }
    if (peak > 1) ans = min (ans, seconds (peak));
    cout << ans;
}

