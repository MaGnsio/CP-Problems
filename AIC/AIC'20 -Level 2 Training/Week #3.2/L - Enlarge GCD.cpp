//https://vjudge.net/contest/419723#problem/L
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mx = 15000000;
bool isprime[mx + 1];
ll prime[mx + 1], cnt[mx + 1], pcnt = 0;

ll gcd (ll a, ll b) {return b ? gcd (b, a % b) : a;}
void seive ()
{
    memset (isprime, true, sizeof (isprime));
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i <= mx; ++i)
    {
        if (isprime[i])
        {
            prime[pcnt++] = i;
            for (ll j = 2 * i; j <= mx; j += i) isprime[j] = false;
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    seive ();
    ll n, g = 0;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (auto& x : a) g = gcd (g, x);
    for (auto& x : a) cnt[x / g]++;
    ll ans = n;
    for (ll i = 0; i < pcnt; ++i)
    {
        ll temp = 0;
        for (ll j = prime[i]; j <= mx; j += prime[i]) temp += cnt[j];
        ans = min (ans, n - temp);
    }
    cout << (ans == n ? -1 : ans);
}

