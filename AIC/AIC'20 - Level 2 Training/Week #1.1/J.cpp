//https://vjudge.net/contest/416230#problem/J
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

// the length of a Pisano Period for a given m ranges from 3 to m * m
ll pisano (ll m)
{
    ll a = 0, b = 1, c = a + b;
    if (m == 1) return 1;
    for (ll i = 0; i < m * m; i++)
    {
        c = ((a % m) + (b % m)) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n;
    cin >> n;
    cout << pisano (n);
}

