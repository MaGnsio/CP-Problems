//https://atcoder.jp/contests/abc189/tasks/abc189_b
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
    ll n, x;
    double m = 0;
    cin >> n >> x;
    pair<double, double> a[n];
    for (auto& X : a) cin >> X.F >> X.S;
    for (ll i = 0; i < n; ++i)
    {
        m += (a[i].F * a[i].S / 100);
        if (m > x + 1e-9) return cout << i + 1, 0;
    }
    cout << -1;
}

