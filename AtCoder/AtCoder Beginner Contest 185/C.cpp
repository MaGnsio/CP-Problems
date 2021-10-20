//https://atcoder.jp/contests/abc185/tasks/abc185_c
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
    ll l, ans = 1;
    cin >> l;
    for (ll i = 1; i <= 11; ++i) ans = ans * (l - i) / i;
    cout << ans;
}

