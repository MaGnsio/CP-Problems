//https://vjudge.net/contest/416254#problem/O
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll getpow (ll e)
{
    ll s = 1;
    while (s * e <= 10e16) s *= e;
    return s;
}
void solve ()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    ll v = getpow (k);
    while (v)
    {
        bool chk = true;
        for (ll i = 0; i < n; ++i)
        {
            if (a[i] >= v)
            {
                if (chk) a[i] -= v, chk = false;
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
        v /= k;
    }
    for (auto& elem : a)
    {
        if (elem)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

