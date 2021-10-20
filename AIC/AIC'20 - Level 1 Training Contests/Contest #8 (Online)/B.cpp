//https://codeforces.com/group/aDFQm4ed6d/contest/277178/problem/B
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
    ll n, k, s = 0;
    cin >> n >> k;
    if (n % k) return cout << -1, 0;
    ll a[n];
    for (auto& X : a) cin >> X;
    sort (a ,a + n);
    for (ll i = 0; i < n; i += n / k) s += a[i + (n / k) - 1] - a[i];
    cout << s;
}

