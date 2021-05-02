//https://codeforces.com/gym/102953/problem/2
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, m, k, sum = 0;
    cin >> n >> m >> k;
    ll a[n];
    for (auto& x : a) cin >> x;
    sort (a, a + n, greater<ll> ());
    for (ll i = 0; i < min (n, m + (m - 1) * (k - 1)); ++i) sum += a[i];
    cout << sum;
}

