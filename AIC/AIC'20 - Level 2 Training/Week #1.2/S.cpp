//https://vjudge.net/contest/416254#problem/S
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
    ll a, b, cnt = 0;
    cin >> a >> b;
    for (ll i = 0; (1LL << i - 1) <= b; ++i)
    {
        for (ll j = 0; j <= i - 2; ++j)
        {
            ll x = (1LL << i) - 1 - (1LL << j);
            cnt += (a <= x && x <= b);
        }
    }
    cout << cnt;
}

