//https://vjudge.net/contest/419723#problem/D
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll gcd (ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}
ll bs (vector<ll>& v,ll l,ll r)
{
    ll i = 0, j = v.size () - 1, ans = -1;
    while (i <= j)
    {
        ll mid = i + (j - i) / 2;
        if (v[mid] <= r)
        {
            i = mid + 1;
            if (v[mid] >= l) ans = v[mid];
        }
        else j = mid - 1;
    }
    return ans;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll a, b, q;
    cin >> a >> b;
    ll g = gcd (a, b);
    vector<ll> factors;
    for (ll i = 1; i * i <= g; ++i)
    {
        if (g % i == 0)
        {
            factors.push_back (i);
            if (i * i != g) factors.push_back (g / i);
        }
    }
    sort (factors.begin (), factors.end ());
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll gf = bs (factors, l, r);
        cout << gf << "\n";
    }
}

