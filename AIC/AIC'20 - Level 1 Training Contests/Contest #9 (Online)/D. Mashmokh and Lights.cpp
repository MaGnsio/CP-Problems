//https://codeforces.com/group/aDFQm4ed6d/contest/278613/problem/D
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
    int n, m, cnt = 0;
    cin >> n >> m;
    ll dp[n] = {};
    while (m--)
    {
        int x;
        cin >> x;
        for (ll i = x - 1; i < n; ++i) if (!dp[i]) dp[i] = x, cnt++;
        if (cnt == n) break;
    }
    for (auto& x : dp) cout << x << " "; 
}

