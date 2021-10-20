//https://atcoder.jp/contests/abc190/tasks/abc190_d
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
    ll n, ans = 0;
    cin >> n;
    while (n % 2 == 0) n /= 2;
    for (ll i = 1; i * i <= n; ++i) if (n % i == 0) ans += 1 + (i * i != n);
    cout << 2 * ans;
}

