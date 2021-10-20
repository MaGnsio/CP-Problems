//https://codeforces.com/gym/102892/problem/6
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
    ll n, m, ans = 1;
    cin >> n >> m;
    ll a[n], b[m];
    map<ll, ll> k;
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j) k[a[i] - b[j]]++;
    }
    for (auto& x : k) ans = max (ans, x.S);
    cout << ans;
}

