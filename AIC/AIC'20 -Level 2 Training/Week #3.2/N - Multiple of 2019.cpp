//https://vjudge.net/contest/419723#problem/N
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
    string s;
    cin >> s;
    ll ans = 0, p = 1, cur = 0;
    ll dp[2019] = {};
    for (ll i = s.size () - 1; i >= 0; --i)
    {
        cur = (cur + (s[i] - '0') * p) % 2019;
        p = (p * 10) % 2019;
        dp[cur]++;
    }
    for (ll i = 0; i < 2019; ++i) ans += dp[i] * (dp[i] - 1) / 2;
    cout << ans + dp[0];
}
