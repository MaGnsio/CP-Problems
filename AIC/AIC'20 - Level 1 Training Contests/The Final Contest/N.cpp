//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/N
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 10000007;


vector<bool> isprime(sz, true);
vector<ll> v(sz, 0);

void init ()
{
    v[0] = v[1] = 0;
    for (ll i = 2; i <= sz; ++i)
    {
        if (isprime[i])
        {
            for (ll j = i; j <= sz; j += i)
            {
                if (!v[j]) v[j] = i;
                isprime[j] = false;
            }
        }
    }
    for (ll i = 2; i < sz; ++i) v[i] += v[i - 1];
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
        cout << v[x] << "\n";
    }
}

