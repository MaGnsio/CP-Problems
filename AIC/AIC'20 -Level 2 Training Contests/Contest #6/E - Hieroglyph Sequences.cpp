//https://vjudge.net/contest/420442#problem/E
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
    ll n, s = 0;
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        s ^= x;
    }
    if (s) cout << 1;
    else cout << 0;
}

