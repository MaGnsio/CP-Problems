//https://vjudge.net/contest/421809#problem/I
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
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; ++i) cin >> v[i];
    if (n < 3 || n % 2 == 0) return cout << -1, 0;
    for (ll i = n; i >= 1; i -= 2)
    {
        ll dec = max (v[i], v[i - 1]);
        v[(i - 1) / 2] = max (0LL, v[(i - 1) / 2] - dec);
        v[i - 1] = max (0LL, v[i - 1] - dec);
        v[i] = max (0LL, v[i] - dec);
        cnt += dec;
    }
    cnt += v[1];
    cout << cnt;
}

