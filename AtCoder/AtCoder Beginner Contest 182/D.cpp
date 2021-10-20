//https://atcoder.jp/contests/abc182/tasks/abc182_d
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
    vector<ll> v(n), q(n);
    for (auto& x : v) cin >> x;
    q[0] = max (0ll, v[0]);
    for (ll i = 1; i < n; ++i)
    {
        v[i] += v[i - 1];
        q[i] = max (q[i - 1], v[i]);
    }
    ll x = LLONG_MIN, currx = 0;
    for (ll i = 0; i < n; ++i) x = max (x, currx + q[i]), currx += v[i];
    cout << x;
}

