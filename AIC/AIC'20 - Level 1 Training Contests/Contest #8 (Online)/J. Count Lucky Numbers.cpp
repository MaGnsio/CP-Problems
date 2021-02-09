//https://codeforces.com/group/aDFQm4ed6d/contest/277178/problem/J
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

const ll sz = 1e7 + 1;
ll dp[sz];
void init ()
{
    for (ll i = 1; i < sz; ++i)
    {
        ll x = i;
        ll a[10] = {};
        bool chk = true;
        while (x)
        {
           a[x % 10]++;
           x /= 10;
        }
        for (auto& Y : a) if (Y > 1) {chk = false; break;}
        if (chk) dp[i]++;
    }
    for (ll i = 1; i < sz; ++i) dp[i] += dp[i - 1];
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << "\n";
    }
    
}

