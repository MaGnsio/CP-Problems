//https://codeforces.com/group/nVgev28wQI/contest/308101/problem/F
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
    ll n, m, i = 0, ans = 0;
    cin >> n >> m;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    sort (a, a + n, greater<ll> ());
    while (m-- && i < n) ans += a[i++];
    cout << ans;
}

