//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/E
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
    ll n, sum = 0;
    ll a[1001] = {};
    cin >> n;
    while (n--)
    {
        ll x;
        cin >> x;
        a[x]++;
    }
    sort (a, a + 1001, greater<ll> ());
    for (ll i = 1; i < 1001; ++i) sum += a[i];
    if (sum >= a[0] - 1) cout << "YES";
    else cout << "NO";
}

