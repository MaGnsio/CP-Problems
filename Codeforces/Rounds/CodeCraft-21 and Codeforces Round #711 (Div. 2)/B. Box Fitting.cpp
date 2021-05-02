//https://codeforces.com/contest/1498/problem/B
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
        ll n, w;
        vector<ll> v (20, 0);
        cin >> n >> w;
        for(ll i = 0; i < n; ++i)
        {
            ll x;
            cin >> x;
            v[log2 (x)]++;
        }
        ll cur = w, h = 1;
        for (ll i = 0; i < n; ++i)
        {
            ll idx = -1;
            for (ll j = 19; j >= 0; --j) if ((v[j]) && (1 << j <= cur))
            {
                idx = j;
                break;
            }
            if (idx == -1)
            {
                cur = w;
                i--;
                h++;
            }
            else
            {
                cur -= (1 << idx);
                v[idx]--;
            }
        }
        cout << h << "\n";
    }
}

