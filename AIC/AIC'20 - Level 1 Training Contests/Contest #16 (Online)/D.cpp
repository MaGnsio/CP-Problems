//https://codeforces.com/group/aDFQm4ed6d/contest/288718/problem/D
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
    ll n, cnt = 0;
    cin >> n;
    for (ll i = n; i % 2 == 0; i /= 2) cnt++;
    for (ll i = n + 1; i % 2 == 0; i /= 2) cnt++;
    cout << (cnt > 1 ? 0 : 1);
}

