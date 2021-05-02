//https://atcoder.jp/contests/abc180/tasks/abc180_d
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
    ll x, y, a, b, ans = 0;
    cin >> x >> y >> a >> b;
    while (x * a > 0 && x * a < x + b && x * a < y) x *= a, ans++;
    cout << ans + (y - 1 - x) / b;
}

