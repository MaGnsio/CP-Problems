//https://vjudge.net/contest/415649#problem/E
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, n;
        cin >> x >> n;
        ll v[n] = {};
        if (n == 1)
        {
            cout << x << "\n";
            continue;
        }
        for (ll i = 0; i < n && x > 0; ++i, --x) v[i]++;
        ll y = x / (n - 1), r = x % (n - 1);
        if (x > 0)
        {
            if (y & 1)
            {
                v[0] += (y / 2) + 1, v[n - 1] += y / 2;
                for (ll i = 1; i < n - 1; ++i) v[i] += y;
                for (ll i = 1; r > 0; --r, ++i) v[i]++;
            }
            else
            {
                v[0] += y / 2, v[n - 1] += y / 2;
                for (ll i = 1; i < n - 1; ++i) v[i] += y;
                for (ll i = n - 2; r > 0; --r, --i) v[i]++;
            }
        }
        for (auto& elem : v) cout << elem << " ";
        cout << "\n";
    }
}

