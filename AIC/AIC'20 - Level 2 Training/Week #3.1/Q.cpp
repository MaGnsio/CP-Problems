//https://vjudge.net/contest/419722#problem/Q
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
    ll N, X, M = 0, G = 0;
    cin >> N;
    for (ll i = 0; i <= N; ++i) {cin >> X; M = max (M, X), G = gcd (G, X);}
    cout << ((M / G - N) & 1 ? "Alice" : "Bob");
}

