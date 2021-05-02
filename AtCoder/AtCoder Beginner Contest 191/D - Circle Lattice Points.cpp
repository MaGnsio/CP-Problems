//https://atcoder.jp/contests/abc191/tasks/abc191_d
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
    double x, y, r;
    cin >> x >> y >> r;
    ll X = round (x * 10000);
    ll Y = round (y * 10000);
    ll R = round (r * 10000);
    ll S = ceil ((X - R) / 10000.0);
    ll E = floor ((X + R) / 10000.0);
    ll cnt = 0;
    for (ll i = S; i <= E; ++i)
    {
        ll A = sqrtl (R * R - (X - i * 10000) * (X - i * 10000));
        ll F = ceil ((Y - A) / 10000.0);
        ll T = floor ((Y + A) / 10000.0);
        cnt += (T - F + 1);
    }
    cout << cnt;
}

