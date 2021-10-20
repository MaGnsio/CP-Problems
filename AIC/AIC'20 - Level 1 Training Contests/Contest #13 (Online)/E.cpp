//https://codeforces.com/group/aDFQm4ed6d/contest/286323/problem/E
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
    ll n, sum = 0;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    sort (a, a + n);
    for (ll i = 0; i < n - 1; ++i) sum += a[i] * (i + 2);
    cout << sum + a[n - 1] * (n);
}

