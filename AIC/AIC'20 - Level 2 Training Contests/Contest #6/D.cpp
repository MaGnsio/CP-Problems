//https://vjudge.net/contest/420442#problem/D
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

double fact[10'000'001];
void init ()
{
    fact[0] == fact[1] == 1.0;
    for (ll i = 2; i < 10'000'001; ++i) fact[i] = fact[i - 1] + log10 ((double)i);
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll l = 1, r = 10'000'000, x = -1;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            double f = fact[mid], g = (double) mid * log10 (n);
            if (f > g) r = mid - 1, x = mid;
            else l = mid + 1;
        }
        cout << x << "\n";
    }
}

