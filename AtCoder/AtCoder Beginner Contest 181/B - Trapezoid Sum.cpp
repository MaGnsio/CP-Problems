//https://atcoder.jp/contests/abc181/tasks/abc181_b
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
    ll n, sum = 0;
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        sum += b * (b + 1) / 2 - a * (a - 1) / 2;
    }
    cout << sum;
}

