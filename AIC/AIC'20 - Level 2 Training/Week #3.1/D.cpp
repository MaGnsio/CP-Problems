//https://vjudge.net/contest/419722#problem/D
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

vector<ll> dp(1500);
void init ()
{
    vector<ll> p;
    p.push_back (2);
    function<bool (ll)> f = [] (ll x) {for (ll i = 2; i * i <= x; ++i) if (x % i == 0) return false; return true;};
    for (ll i = 3; i <= 999; i += 2) if (f (i)) p.push_back (i);
    for (ll i = 0; i < p.size () - 1; ++i) if (f (p[i] + p[i + 1] + 1)) dp[p[i] + p[i + 1] + 1]++;
    for (ll i = 1; i < 1500; ++i) dp[i] += dp[i - 1];
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll n, k;
    cin >> n >> k;
    if (dp[n] >= k) cout << "YES";
    else cout << "NO";
}

