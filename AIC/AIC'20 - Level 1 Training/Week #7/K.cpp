//https://codeforces.com/group/Rv2Qzg0DgK/contest/285699/problem/K
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
    ll n, m, q;
    cin >> n >> m;
    ll a[n], dp[n + 1] = {};
    unordered_set<ll> s;
    for (auto& elem : a) cin >> elem;
    for (ll i = n - 1; i >= 0; --i)
    {
        s.insert (a[i]);
        dp[i + 1] = s.size ();
    }
    while (m--)
    {
        cin >> q;
        cout << dp [q] << "\n";
    }
}

