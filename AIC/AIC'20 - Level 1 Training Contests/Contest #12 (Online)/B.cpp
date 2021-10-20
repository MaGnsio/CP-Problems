//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/B
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
    ll n, m;
    cin >> n >> m;
    ll a[m];
    for (auto& x : a) cin >> x;
    sort (a, a + m);
    if (a[0] == 1 || a[m - 1] == n) return cout << "NO", 0;
    for (ll i = 0; i < m - 2; ++i)
    {
        if (a[i + 1] == a[i] + 1 && a[i + 2] == a[i] + 2) return cout << "NO", 0;
    }
    cout << "YES";
}

