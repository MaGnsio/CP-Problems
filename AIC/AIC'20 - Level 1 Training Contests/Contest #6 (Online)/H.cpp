//https://codeforces.com/group/aDFQm4ed6d/contest/274872/problem/H
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
    ll k, n, s, p;
    cin >> k >> n >> s >> p;
    ll x = (n + s - 1) / s;
    cout << ((k * x) + p - 1) / p;
}

