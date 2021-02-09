//https://vjudge.net/contest/416254#problem/A
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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld d = sqrt (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    cout << fixed << setprecision (9) << d;
}

