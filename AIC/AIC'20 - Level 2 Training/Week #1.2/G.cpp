//https://vjudge.net/contest/416254#problem/G
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
    ll a[4], b[4];
    for (ll i = 0; i < 4; ++i) cin >> a[i] >> b[i];
    sort (a, a + 4);
    sort (b, b + 4);
    ll x1 = a[0], x2 = a[3], y1 = b[0], y2 = b[3], q, px, py;
    cin >> q;
    while (q--)
    {
        cin >> px >> py;
        if (px <= x2 && px >= x1 && py <= y2 && py >= y1) cout << "YES\n";
        else cout << "NO\n";
    }
}

