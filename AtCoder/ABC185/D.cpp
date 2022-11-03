//https://atcoder.jp/contests/abc185/tasks/abc185_d
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
    ll n, m, ans = 0;
    cin >> n >> m;
    if (!m) return cout << 1, 0;
    vector<ll> v(m);
    for (auto& x : v) cin >> x;
    sort (v.begin (), v.end ());
    ll k = (v[0] - 1 > 0 && n - v[m - 1] > 0 ? min (v[0] - 1, n - v[m - 1]) : (v[0] - 1 <= 0 && n - v[m - 1] <= 0 ? LLONG_MAX : max (v[0] - 1, n - v[m - 1])));
    for (ll i = 1; i < m; ++i)
    {
        if (v[i] - v[i - 1] - 1 == 0) continue;
        k = min (k, v[i] - v[i - 1] - 1);
    }
    if (k == LLONG_MAX) return cout << 0, 0;
    for (ll i = 1; i < m; ++i)
    {
        ll temp = v[i] - v[i - 1] - 1;
        ans += (temp + k - 1) / k;
    }
    ans += (v[0] - 1 ? (v[0] - 1 + k - 1) / k : 0) + (v[m - 1] != m ? (n - v[m - 1] + k - 1) / k : 0);
    cout << ans;
}
