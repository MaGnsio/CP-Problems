//https://codeforces.com/group/aDFQm4ed6d/contest/287686/problem/C
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll gcd (ll a, ll b) {return (b ? gcd (b, a % b) : a);}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, k;
    cin >> n >> k;
    ll p = pow (10, k);
    cout << n * p / gcd (n, p);
}

