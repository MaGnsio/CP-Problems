//https://vjudge.net/contest/419723#problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

vector<bool> isprime (1000, true);
vector<ll> prime;
void init ()
{
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i < 1000; ++i)
    {
        if (isprime[i])
        {
            prime.push_back (i);
            for (ll j = 2 * i; j < 1000; j += i) isprime[j] = false;
        }
    }
}
void solve (ll c)
{
    ll n, ans = 1;
    vector<ll> cnt (prime.size (), 0);
    string s;
    cin >> n >> s;
    ll k = s.size ();
    for (ll i = n; i > 1; i -= k)
    {
        for (ll j = 0; j < cnt.size (); ++j)
        {
            ll cpy = i;
            while (cpy % prime[j] == 0) cpy /= prime[j], cnt[j]++;
        }
    }
    for (ll i = 0; i < cnt.size (); ++i)
    {
        ans *= (cnt[i] + 1);
        if (ans < 0 || ans > 1000000000000000000)
        {
            cout << "Case " << c << ": Infinity\n";
            return;
        }
    }
    cout << "Case " << c << ": " << ans << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll t, c = 0;
    cin >> t;
    while (t--) solve (++c);
}

