//https://vjudge.net/contest/416230#problem/D
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
    ll n;
    cin >> n;
    if (n <= 1) return cout << 1, 0;
    ld ans = ((n * log10 (n / 2.71828182845904523536) + log10 (2 * 3.141592654 * n) /2.0));
    cout << (ll) (floor (ans) + 1);
}

