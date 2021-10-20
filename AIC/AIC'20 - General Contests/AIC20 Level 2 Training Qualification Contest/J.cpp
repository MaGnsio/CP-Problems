//https://codeforces.com/group/nVgev28wQI/contest/308101/problem/J
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
    ll a, b, ans = LLONG_MAX;
    cin >> a >> b;
    if (b - a >= 2020)
    {
        cout << 0;
        return 0;
    }
    else
    {
        for (ll i = a; i < b; ++i)
        {
            for (ll j = i + 1; j <= b; ++j) ans = min (ans, ((i % 2020) * (j % 2020)) % 2020);
        }
        cout << ans;
    }
}

