//https://vjudge.net/contest/416230#problem/K
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
    ll a, b;
    cin >> a >> b;
    ll m1[a][b];
    for (auto& rows : m1) for (auto& elem : rows) cin >> elem;
    ll x, y;
    cin >> x >> y;
    ll m2[x][y];
    for (auto& rows : m2) for (auto& elem : rows) cin >> elem;
    for (ll i = 0; i < a; ++i)
    {
        for (ll j = 0; j < y; ++j)
        {
            ll elem = 0;
            for (ll k = 0; k < b; ++k) elem += m1[i][k] * m2[k][j];
            cout << elem << " ";
        }
        cout << "\n";
    }
}

