//https://vjudge.net/contest/416254#problem/V
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
    ll n, k, p = (1LL << 40), f = 0, x = 0;
    cin >> n >> k;
    ll a[n], b[41] = {};
    for (auto& elem : a)
    {
        cin >> elem;
        for (ll i = 0; i < 41; ++i) if (elem & (1LL << i)) b[i]++;
    }
    for (ll i = 40; i >= 0; --i)
    {
        ll ctr_1 = b[i], ctr_0 = n - b[i];
        if (ctr_1 >= ctr_0) f += (ctr_1 * p);
        else
        {
            if (x + p <= k) f += (ctr_0 * p), x += p;
            else f += (ctr_1 * p);
        }
        p /= 2;
    }
    cout << f;
}

