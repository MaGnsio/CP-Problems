//https://vjudge.net/contest/417537#problem/A
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a && b && c && a + b + c == 180 && (a + b >= c || a + c >= b || a + c >= b)) cout << "YES\n";
        else cout << "NO\n";
    }
}

