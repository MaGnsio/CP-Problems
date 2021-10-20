//https://codeforces.com/group/aDFQm4ed6d/contest/287062/problem/E
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a, b, cnt = 1;
        cin >> n >> a >> b;
        ll x = abs (a - b);
        for (ll i = 2; i * i <= x; ++i)
        {
            if (x % i == 0)
            {
                ll tmp = 0;
                while (x % i == 0) x /= i, tmp++;
                cnt *= (tmp + 1);
            }
        }
        if (x > 1) cnt *= 2;
        cout << cnt << "\n";
    }
}

