//https://codeforces.com/contest/1496/problem/B
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
    while (t--) {
        ll n, k;
        set<ll> s;
        cin >> n >> k;
        for (ll i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            s.insert (x);
        }
        if (k == 0) {
            cout << s.size () << "\n";
            continue;
        }
        ll max = *s.rbegin (), mex = 0;
        for (auto it = s.begin (); it != s.end (); ++it, ++mex) if (*it != mex) {
            break;
        }
        if (mex > max) cout << s.size () + k << "\n";
        else cout << s.size () + !s.count ((mex + max + 1) / 2) << "\n";
    }
}

