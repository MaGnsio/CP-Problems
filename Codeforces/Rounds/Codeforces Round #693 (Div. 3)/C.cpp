//https://codeforces.com/contest/1472/problem/C
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n), dp(n);
        for (auto& elem : v) cin >> elem;
        for (ll i = n - 1; i >= 0; --i)
        {
            dp[i] = v[i];
            if (v[i] + i < n) dp[i] += dp[v[i] + i];
        }
        cout << *max_element (dp.begin (), dp.end ()) << "\n";
    }
}

