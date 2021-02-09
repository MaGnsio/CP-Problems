//https://vjudge.net/contest/417537#problem/E
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, k, cnt = 0, ans = 0;
    vector<ll> v;
    string s;
    cin >> n >> k >> s;
    v.push_back (-1);
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            v.push_back (i);
            cnt++;
        }
    }
    v.push_back (n);
    if (cnt < k)
    {
        cout << 0 << "\n";
        return;
    }
    if (!k)
    {
        for (ll i = 1; i <= cnt + 1; ++i)
        {
            ll x = v[i] - v[i - 1] - 1;
            ans += (x * (x + 1) / 2);
        }
        cout << ans << "\n";
        return;
    }
    for (ll i = 1; i <= cnt; ++i)
    {
        if (i + k - 1 > cnt) break;
        ll j = i + k - 1;
        ll before = v[i] - v[i - 1];
        ll after = v[j + 1] - v[j];
        ans += (before * after);
    }
    cout << ans << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}
