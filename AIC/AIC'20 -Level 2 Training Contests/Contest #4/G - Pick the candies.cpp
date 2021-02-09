//https://vjudge.net/contest/417537#problem/G
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    vector<ll> v;
    unordered_multiset<ll> s;
    for (ll i = 0; i < k; ++i) s.insert (a[i]);
    for (ll i = k; i < n; ++i)
    {
        v.push_back (*max_element (s.begin (), s.end ()));
        for (auto it = s.begin (); it != s.end (); ++it) if (*it == a[i - k]) s.erase (it);
        s.insert (a[i]);
    }
    v.push_back (*max_element (s.begin (), s.end ()));
    for (auto& elem : v) cout << elem << " ";
    cout << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

