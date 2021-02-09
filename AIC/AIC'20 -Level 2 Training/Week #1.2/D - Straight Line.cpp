//https://vjudge.net/contest/416254#problem/D
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
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (((x2 * y3) - (y2 * x3)) + ((x3 * y1) - (x1 * y3)) + ((x1 * y2) - (x2 * y1)) == 0) cout << "YES";
    else cout << "NO";
}

