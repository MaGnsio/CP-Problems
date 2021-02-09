//https://vjudge.net/contest/419722#problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

const ll sz = 1'000'001;
vector<bool> isprime(sz, true);
vector<ll> seive(sz), a(sz, LLONG_MAX), b(sz, 0), c(sz, 0), d(sz, 0), e(sz, 1), f(sz, 1);

void init ()
{
    function<ll (ll, ll)> p = [] (ll a, ll b) -> ll {ll ans = 1; while (b--) ans *= a; return ans;}; //return a^b
    isprime[0] = isprime[1] = false; //set 0 & 1 to not prime
    for (ll i = 2; i < sz; ++i)
    {
        if (isprime[i]) //if i is prime
        {
            for (ll j = i; j <= sz; j += i) //chk its multiples
            {
                isprime[j] = false; //set them to not prime
                ll cpy = j, cnt = 0;
                while (cpy % i == 0) cpy /= i, cnt++; //(i^cnt)
                a[j] = min (i, a[j]); //the least prime factor of j
                b[j] = max (i, b[j]); //the greatest prime factor of j
                c[j]++; //the number of distinct prime factors of j
                d[j] += cnt; //the total number of prime factors of j
                e[j] *= (cnt + 1); //denotes the number of divisors of j (cnt + 1) * ...
                f[j] *= (p (i, cnt + 1) - 1) / (i - 1); //the sum of divisors of j ((i^(cnt + 1) - 1) / (i - 1)) * ...
            }
            isprime[i] = true; //to maintain the validity of isprime vector
        }
    }
}

void solve ()
{
    ll x;
    cin >> x;
    cout << a[x] << " " << b[x] << " " << c[x] << " " << d[x] << " " << e[x] << " " << f[x] << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll n;
    cin >> n;
    while (n--) solve ();
}

