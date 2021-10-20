//https://vjudge.net/contest/414669#problem/F
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
        ll n, k, ans = 0;
        multiset<ll> s;
        cin >> n >> k;
        ll a[n];
        for (auto& elem : a) cin >> elem;
        for (ll i = 0; i < n; ++i)
        {
            s.insert (a[i]);
            if (i > k + 1) s.erase (s.find (a[i - k - 2]));
            ans = max (ans, *(s.rbegin ()) - *(s.begin ()));
        }
        cout << ans << "\n";
    }
}

