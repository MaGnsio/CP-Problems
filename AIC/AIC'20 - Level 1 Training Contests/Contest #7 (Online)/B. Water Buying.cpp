//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, a, b;
    cin >> n >> a >> b;
    if (2 * a <= b) cout << a * n << "\n";
    else cout << b * (n / 2) + a * (n % 2) << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

