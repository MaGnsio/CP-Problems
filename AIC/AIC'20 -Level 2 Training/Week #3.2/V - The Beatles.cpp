//https://vjudge.net/contest/419723#problem/V
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll gcd (ll a, ll b) {return (b ? gcd (b, a % b) : a);}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    ll mi = LLONG_MAX, ma = LLONG_MIN;
    for (ll i = 0; i < n; ++i)
    {
        ll l1 = i * k + a + b;
        ll l2 = (i + 1) * k + a - b;
        ll l3 = i * k + b - a;
        ll l4 = (i + 1) * k - b - a;
        if (l1 <= 0) l1 += k;
        if (l2 <= 0) l2 += k;
        if (l3 <= 0) l3 += k;
        if (l4 <= 0) l4 += k;
        ll m1 = n * k / (gcd (n * k, l1));
        ll m2 = n * k / (gcd (n * k, l2));
        ll m3 = n * k / (gcd (n * k, l3));
        ll m4 = n * k / (gcd (n * k, l4));
        mi = min ({mi, m1, m2, m3, m4});
        ma = max ({ma, m1, m2, m3, m4});
    }
    cout << mi << " " << ma;
}
// a <-mk-> S0 <---> a <-mk-> b <---> S1 <---> b "probabilities of where a and b could be exist"
// number of moves = lcm (n * k, l) / l = n * k / gcd (n * k, l) : lcm (n * k, l) is the total distance to rich city S again
