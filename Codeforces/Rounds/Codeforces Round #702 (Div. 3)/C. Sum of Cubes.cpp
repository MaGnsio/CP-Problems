//https://codeforces.com/contest/1490/problem/C
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1e12;

unordered_set<ll> s;

void init ()
{
    for (ll i = 1; i * i * i <= sz; ++i) s.insert (i * i * i);
}
void solve ()
{
    ll n;
    cin >> n;
    for (ll i = 1; i * i * i <= n; ++i)
    {
        if (s.count (n - i * i * i))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

