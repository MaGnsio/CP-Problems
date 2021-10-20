//https://vjudge.net/contest/414669#problem/A
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
    ll t, a, b;
    cin >> t;
    while (t--)
    {
        ll na = 0, nb = 0, p = 1;
        cin >> a >> b;
        while (a) na = (na * 10) + (a % 10), a /= 10;
        p = 1;
        while (b) nb = (nb * 10) + (b % 10), b /= 10;
        ll s = na + nb, ns = 0;
        p = 1;
        while (s) ns = (ns * 10) + (s % 10), s /= 10;
        cout << ns << "\n";
    }
}

