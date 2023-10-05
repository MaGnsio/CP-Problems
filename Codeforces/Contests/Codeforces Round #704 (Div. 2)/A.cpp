//https://codeforces.com/contest/1492/problem/A
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        if (p % a == 0 || p % b == 0 || p % c == 0) cout << 0 << "\n";
        else cout << min ({a - (p % a), b - (p % b), c - (p % c)}) << "\n";
    }
}

