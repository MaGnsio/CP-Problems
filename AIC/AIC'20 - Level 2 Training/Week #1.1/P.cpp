//https://vjudge.net/contest/416230#problem/P
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
    ll a, b;
    cin >> a >> b;
    if (b > a) swap (a, b);
    ll x = (a - b + 1) * (a + b) / 2;
    if (a % 2) a--;
    if (b % 2) b++;
    ll y = (a < b ? 0ll : (((a - b + 1) / 2) + 1) * (a + b) / 2);
    ll z = x - y;
    cout << x << "\n" << y << "\n" << z;
}

