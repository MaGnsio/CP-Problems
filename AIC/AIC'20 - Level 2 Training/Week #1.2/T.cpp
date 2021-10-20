//https://vjudge.net/contest/416254#problem/T
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
    ll x = (a - 1) % 4, y = b % 4;
    if (x == 0) a -= 1;
    else if (x == 1) a = 1;
    else if (x == 3) a = 0;
    if (y == 1) b = 1;
    else if (y == 2) b += 1;
    else if (y == 3) b = 0;
    cout << (a ^ b);
}

