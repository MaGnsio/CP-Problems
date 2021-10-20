//https://vjudge.net/contest/417537#problem/I
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
    ll n, m, x = 0;
    cin >> n >> m;
    ll a[n][m];
    ll b[n] = {};
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
        x ^= a[i][0];
    }
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            if ((x ^ a[i][0]) ^ a[i][j])
            {
                b[i] = j;
                cout << "TAK\n";
                for (auto& elem : b) cout << elem + 1 << " ";
                return 0;
            }
        }
    }
    cout << "NIE";
}

