//https://atcoder.jp/contests/abc193/tasks/abc193_c
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1e10;

set<ll> s;
void init ()
{
    for (ll i = 2; i * i <= sz; ++i)
    {
        for (ll j = i * i; j <= sz; j *= i) s.insert (j);
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll n;
    cin >> n;
    ll cnt = n - distance (s.begin (), lower_bound (s.begin (), s.end (), n)) - s.count (n);
    cout << cnt;
}

