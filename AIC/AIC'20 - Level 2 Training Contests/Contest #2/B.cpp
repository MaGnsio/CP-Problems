//https://vjudge.net/contest/415649#problem/B
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
    ll n, t = 0;
    cin >> n;
    for (ll i = 1; t != n; i += n + 1, t++) cout << i << " "; 
}

