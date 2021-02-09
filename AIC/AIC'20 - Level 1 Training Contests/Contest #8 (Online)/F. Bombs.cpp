//https://codeforces.com/group/aDFQm4ed6d/contest/277178/problem/F
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
    char a[30][30];
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1; j <= m; ++j)
        {
            if (a[i][j] == 'o')
            {
                if (a[i - 1][j - 1] != 'o') a[i - 1][j - 1] = 'x';
                if (a[i - 1][j] != 'o') a[i - 1][j] = 'x';
                if (a[i - 1][j + 1] != 'o') a[i - 1][j + 1] = 'x';
                if (a[i][j - 1] != 'o') a[i][j - 1] = 'x';
                a[i][j] = 'x';
                if (a[i][j + 1] != 'o') a[i][j + 1] = 'x';
                if (a[i + 1][j - 1] != 'o') a[i + 1][j - 1] = 'x';
                if (a[i + 1][j] != 'o') a[i + 1][j] = 'x';
                if (a[i + 1][j + 1] != 'o') a[i + 1][j + 1] = 'x';
            }
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1; j <= m; ++j) cout << a[i][j];
        cout << "\n";
    }
}

