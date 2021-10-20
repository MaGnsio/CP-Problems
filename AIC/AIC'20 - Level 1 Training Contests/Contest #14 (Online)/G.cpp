//https://codeforces.com/group/aDFQm4ed6d/contest/287062/problem/G
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1e6 + 1;

vector<bool> is_prime (sz, true);
set<ll> s;

void init ()
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < sz; ++i)
    {
        if (is_prime[i])
        {
            s.insert (i * i);
            for (ll j = 2 * i; j < sz; j += i) is_prime[j] = false;
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll n;
    cin >> n;
    while (n--)
    {
        ll x;
        cin >> x;
        cout << (s.count (x) ? "YES\n" : "NO\n");
    }
}

