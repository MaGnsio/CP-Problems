//https://vjudge.net/contest/416230#problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll f (ll n)
{
    if (n == 0) return 1;
    return n * f (n - 1);
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, r;
    cin >> n >> r;
    ll a = f (n) / (f (r) * f (n - r)), b = f (r) * a;
    cout << a << " " << b;
}

