//https://codeforces.com/group/aDFQm4ed6d/contest/296501/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll f (ll n)
{
    if (n <= 1) return 1;
    return n * f (n - 1);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll a, b;
    cin >> a >> b;
    cout << f (min (a, b));
}

