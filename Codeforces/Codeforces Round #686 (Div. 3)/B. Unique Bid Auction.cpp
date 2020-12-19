//https://codeforces.com/contest/1454/problem/B
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
        ll n, x, idx = -1, ans = LLONG_MAX;
        set<ll> s;
        map<ll, ll> m;
        cin >> n;
        for (ll i = 1; i <= n; ++i)
        {
            cin >> x;
            if (s.count (x) == 0)
            {
                m[x] = i;
                s.insert (x);
            }
            else if (m.find (x) != m.end ()) m.erase (m.find (x));
        }
        for (auto& elem : m)
        {
            if (elem.F < ans)
            {
                ans = elem.F;
                idx = elem.S;
            }
        }
        cout << idx << "\n";
    }
}

