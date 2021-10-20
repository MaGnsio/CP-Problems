//https://vjudge.net/contest/416230#problem/M
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
    ll fib[89] = {1, 1};
    for (ll i = 2; i < 89; ++i) fib[i] = fib[i - 1] + fib[i - 2];
    ll n;
    cin >> n;
    cout << fib[n - 1];
}

