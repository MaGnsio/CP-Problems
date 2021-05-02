//https://atcoder.jp/contests/abc194/tasks/abc194_c
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
    ll n, x = 0, y = 0;
    cin >> n;
    ll a[n], b[n];
    for (auto& x : a) cin >> x;
    b[0] = a[0];
    for (int i = 1; i < n; ++i) b[i] = a[i] + b[i - 1];
    for (ll i = 0; i < n; ++i) x += (n - 1) * (a[i] * a[i]);
    for (ll i = 1; i < n; ++i) y += (-2 * a[i] * b[i - 1]);
    cout << x + y;
}

