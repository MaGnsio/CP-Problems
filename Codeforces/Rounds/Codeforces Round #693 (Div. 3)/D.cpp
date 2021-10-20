//https://codeforces.com/contest/1472/problem/D
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
        ll n, s1 = 0, s2 = 0;
        cin >> n;
        ll a[n];
        for (auto& elem : a) cin >> elem;
        sort (a, a + n, greater<ll> ());
        for (ll i = 0; i < n; ++i)
        {
            if (i & 1)
            {
                if (a[i] & 1) s2 += a[i];
                else continue;
            }
            else
            {
                if (!(a[i] & 1)) s1 += a[i];
                else continue;
            }
        }
        if (s1 > s2) cout << "Alice\n";
        else if (s2 > s1) cout << "Bob\n";
        else cout << "Tie\n";
    }
}

