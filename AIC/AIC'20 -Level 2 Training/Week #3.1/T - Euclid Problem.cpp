//https://vjudge.net/contest/419722#problem/T
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll x, y, d;
void EE (ll a, ll b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    EE (b, a % b);
    ll x1, y1;
    x1 = y;
    y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll a, b;
    while (cin >> a >> b)
    {
        EE (a, b);
        cout << x << " " << y << " " << d << "\n";
    }
}

