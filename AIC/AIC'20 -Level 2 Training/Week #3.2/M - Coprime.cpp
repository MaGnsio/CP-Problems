//https://vjudge.net/contest/419723#problem/M
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1000000;

bool isprime[sz + 1];
ll cnt[sz + 1], prime[sz + 1], pcnt = 0;

ll gcd (ll a, ll b) {return (b ? gcd (b, a % b) : a);}
void seive ()
{
    memset (isprime, true, sizeof (isprime));
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i <= sz; ++i)
    {
        if (isprime[i])
        {
            prime[pcnt++] = i;
            for (ll j = 2 * i; j <= sz; j += i) isprime[j] = false;
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    seive ();
    ll n, bairwise = 1, setwise = 0;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (auto& x : a) setwise = gcd (setwise, x);
    for (auto& x : a) cnt[x / setwise]++;
    if (setwise != 1) return cout << "not coprime", 0;
    for (ll i = 0; i < pcnt; ++i)
    {
        ll ctr = 0;
        for (ll j = prime[i]; j <= sz; j += prime[i]) ctr += cnt[j];
        if (ctr > 1)
        {
            bairwise = 0;
            break;
        }
    }
    if (bairwise == 1) cout << "pairwise coprime";
    else cout << "setwise coprime";
}

