//https://vjudge.net/contest/416541#problem/H
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
    ll n, k, cnt = 1, ans = 0;
    string s;
    cin >> n >> k >> s;
    vector<ll> v;
    for (ll i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1]) cnt++;
        else v.push_back (cnt), cnt = 1;
    }
    v.push_back (cnt);
    vector<ll> dp (v.size () + 1, 0);
    for (ll i = 1; i <= v.size (); ++i) dp[i] = v[i - 1] + dp[i - 1];
    for (ll i = 0; i < v.size (); ++i)
    {
        if(s[0] == '1' && i % 2 == 0) continue;
        if(s[0] == '0' && i % 2 == 1) continue;
        ll l = max (0ll, i + 1 - 2);
        ll r = min (i + 1 + (k - 1) * 2 + 1, (ll) v.size ());
        ans = max (dp[r] - dp[l], ans);
    }
    if (!ans) ans = n;
    cout << ans;
}

