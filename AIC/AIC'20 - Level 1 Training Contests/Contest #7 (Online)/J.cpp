//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/J
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
    ll n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    while (k--)
    {
        ll ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        if (ta == tb) cout << abs (fa - fb) << "\n";
        else
        {
            ll y = (fa >= a && fa <= b ? fa : (abs (fa - a) < abs (fa - b) ? a : b));
            ll ans = abs (ta - tb) + abs (y - fa) + abs (y - fb);
            cout << ans << "\n";
        }
    }
}

