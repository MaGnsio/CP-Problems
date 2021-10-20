//https://vjudge.net/contest/419722#problem/Y
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, p, gcd = 1;
    vector<pair<ll, ll>> v;
    cin >> n >> p;
    for (ll i = 2; i * i <= p; ++i)
    {
        ll cnt = 0;
        if (p % i) continue;
        while (p % i == 0) p /= i, cnt++;
        v.push_back ({i, cnt});
    }
    if (p != 1) v.push_back ({p, 1ll});
    for (auto& X : v)
    {
        for (ll i = 0; i < X.S / n; ++i) gcd *= X.F;
    }
    cout << gcd;
}

