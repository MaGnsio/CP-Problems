//https://codeforces.com/contest/1506/problem/A
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
        ll n, m, x;
        cin >> n >> m >> x;
        ll c = (x - 1) / n, r = (x - 1) % n;
        cout << 1 + m * r + c << "\n";
    }
}

