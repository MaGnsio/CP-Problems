//https://atcoder.jp/contests/abc195/tasks/abc195_c
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
    ll n, cnt = 0;
    cin >> n;
    for (ll i = 1000, j = 1, k = 1; i <= n; i *= 10, j++)
    {
        cnt += (min (n + 1ll, i * 10ll) - i) * k;
        if (j % 3 == 0) k++;
    }
    cout << cnt;
}

