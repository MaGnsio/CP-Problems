//https://codeforces.com/group/aDFQm4ed6d/contest/274872/problem/J
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
    ll n, m, cnt = 0;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& X : v) cin >> X;
    for (ll i = 0; i < n; ++i)
    {
        bool chk = true;
        for (ll j = 0; j < m; ++j)
        {
            if (v[i][j] == 'S')
            {
                chk = false;
                break;
            }
        }
        if (chk) for (ll j = 0; j < m; ++j) v[i][j] = 'X';
    }
    for (ll j = 0; j < m; ++j)
    {
        bool chk = true;
        for (ll i = 0; i < n; ++i)
        {
            if (v[i][j] == 'S')
            {
                chk = false;
                break;
            }
        }
        if (chk) for (ll i = 0; i < n; ++i) v[i][j] = 'X';
    }
    for (auto& X : v)
    {
        for (auto& Y : X) if (Y == 'X') cnt++;
    }
    cout << cnt;
}

