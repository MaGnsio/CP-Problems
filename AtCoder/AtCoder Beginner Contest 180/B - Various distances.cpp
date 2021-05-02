//https://atcoder.jp/contests/abc180/tasks/abc180_b
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
    ll n, x = 0, y = 0, z = 0;
    cin >> n;
    ll a[n];
    for (auto& e : a)
    {
        cin >> e;
        if (e < 0) e *= -1;
        x += e;
        y += e * e;
        z = max (z, e);
    }
    ld k = sqrt (y);
    cout << x << "\n" << fixed << setprecision (15) << k << "\n" << z;
}

