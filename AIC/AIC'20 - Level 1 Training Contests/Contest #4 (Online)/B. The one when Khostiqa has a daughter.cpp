//https://codeforces.com/group/aDFQm4ed6d/contest/273591/problem/B
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
    ll n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& elem : v) cin >> elem;
    for (ll i = 0; i < n + 2; ++i)
    {
        for (ll j = 0; j < m + 2; ++j)
        {
            if (i <= n && i > 0 && j > 0 && j <= m) cout << v[i - 1][j - 1];
            else cout << "*";
        }
        cout << "\n";
    }
}

