//https://codeforces.com/group/aDFQm4ed6d/contest/296501/problem/I
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
    ll n;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    sort (a, a + n, greater<ll> ());
    for (ll i = 1; i < n; ++i) a[i] += a[i - 1];
    for (ll i = 0; i < n; ++i) if (a[i] > a[n- 1] - a[i])
    {
        cout << i + 1;
        return 0;
    }
}

