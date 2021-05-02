//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/D
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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll x = min ({a * 4, b * 2, c});
    cout << min (n * x, (n / 2) * d + (n % 2) * x);
}

