//https://vjudge.net/contest/418569#problem/J
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
    ll n, cnt = 0;
    cin >> n;
    ll f[100001] = {};
    while (n--)
    {
        ll x;
        cin >> x;
        f[x]++;
    }
    sort (f, f + 100001, greater<ll> ());
    for (ll i = 1; i < 100001; ++i) cnt += min (f[i], f[i - 1]);
    cout << cnt;
}

