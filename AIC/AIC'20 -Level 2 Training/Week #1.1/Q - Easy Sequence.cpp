//https://vjudge.net/contest/416230#problem/Q
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
    ll a, b, c, q, x;
    cin >> a >> b >> c >> q;
    while (q--)
    {
        cin >> x;
        if ((x - a) % (c - b) == 0 && (x - a) / (c - b) >= 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

