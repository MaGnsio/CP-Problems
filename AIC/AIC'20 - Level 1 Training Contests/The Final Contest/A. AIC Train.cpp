//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/A
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
    ll c, n, m = 0;
    cin >> c >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        if (b > m) return cout << "YES", 0;
        m -= b;
        m += a;
        if (m > c) return cout << "YES", 0;
    }
    cout << (m ? "YES" : "NO");
}

