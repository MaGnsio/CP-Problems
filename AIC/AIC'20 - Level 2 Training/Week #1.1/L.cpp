//https://vjudge.net/contest/416230#problem/L
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
    ll x, y;
    cin >> x >> y;
    ll a[x][y];
    for (auto& rows : a) for (auto& elem : rows) cin >> elem;
    for (ll i = 0; i < y; ++i)
    {
        for (ll j = 0; j < x; ++j) cout << a[j][i] << " ";
        cout << "\n";
    }
}

