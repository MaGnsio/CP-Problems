//https://atcoder.jp/contests/abc189/tasks/abc189_c
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
    ll n, x = 0;
    cin >> n;
    vector<ll> a(n), v;
    for (auto& X : a) cin >> X;
    for (ll i = 0; i < n; ++i)
    {
        ll y = a[i];
        for (ll j = i; j < n; ++j) y = min (y, a[j]), x = max (x, y * (j - i + 1));
    }
    cout << x;
}

