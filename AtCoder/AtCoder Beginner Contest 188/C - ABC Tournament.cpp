//https://atcoder.jp/contests/abc188/tasks/abc188_c
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
    ll n;
    cin >> n;
    vector<ll> v (1 << n);
    map<ll, ll> idx;
    for (auto& x : v) cin >> x;
    for (ll i = 0; i < (1 << n); ++i) idx[v[i]] = i + 1;
    for (ll i = 1; i <= n; ++i)
    {
        ll m = 1 << (n - i);
        vector<ll> temp;
        for (ll j = 0; j < m; ++j)
        {
            if (v[2 * j] > v[2 * j + 1]) temp.push_back (v[2 * j]);
            else temp.push_back (v[2 * j + 1]);
        }
        if (i == n) return cout << idx[min (v[0], v[1])], 0;
        v = temp;
    }
}

