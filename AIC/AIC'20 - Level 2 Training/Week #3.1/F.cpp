//https://vjudge.net/contest/419722#problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

const ll sz = 1'000'500;

vector<bool> isprime (sz, true);
vector<ll> primes, d(sz, 0);

void init ()
{
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i < sz; ++i)
    {
        if (isprime[i])
        {
            primes.push_back (i);
            for (ll j = 2 * i; j < sz; j += i) isprime[j] = false;
        }
    }
    for (ll i = 1; i < primes.size (); ++i)
    {
        ll x = primes[0] + primes[i]; //the tuble will always be 2 + P0 = P1 as only EVEN + ODD = ODD
        if (x < sz && isprime[x]) d[x]++;
    }
    for (ll i = 1; i < sz; ++i) d[i] += d[i - 1];
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll t, x;
    cin >> t;
    while (t--)
    {
        cin >> x;
        cout << d[x] << "\n";
    }
}

