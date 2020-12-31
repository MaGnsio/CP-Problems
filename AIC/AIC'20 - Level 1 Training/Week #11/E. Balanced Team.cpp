//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/E
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
    ll n, ans = 1;
    cin >> n;
    vector<ll> v(n);
    for (auto& elem : v) cin >> elem;
    sort (v.begin (), v.end ());
    for (ll i = 0; i < n; ++i) ans = max  (ans, (ll) (upper_bound (v.begin (), v.end (), v[i] + 5) - v.begin ()) - i);
    cout << ans;
}

