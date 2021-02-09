//https://vjudge.net/contest/420442#problem/J
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

vector<bool> isprime (1'000'01, true);
vector<ll> dp (1'000'01, 0);
void init ()
{
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i < 1'000'01; ++i)
    {
        if (isprime[i])
        {
            for (ll j = 2 * i; j < 1'000'01; j += i) isprime[j] = false;
        }
    }
    for (ll i = 1; i < 1'000'01; i += 2)
    {
        if (isprime[i] && isprime[(i + 1) / 2]) dp[i]++;
    }
    for (ll i = 1; i < 1'000'01; ++i) dp[i] += dp[i - 1];
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << "\n";
    }
}

