//https://vjudge.net/contest/416254#problem/C
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
    ll x, y, r, q, x1, y1;
    cin >> x >> y >> r >> q;
    while (q--)
    {
        cin >> x1 >> y1;
        if (sqrt (((x - x1) * (x - x1)) + ((y - y1) * (y - y1))) <= r) cout << "YES\n";
        else cout << "NO\n";
    }
}

