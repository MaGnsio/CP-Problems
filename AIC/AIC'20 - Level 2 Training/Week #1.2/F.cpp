//https://vjudge.net/contest/416254#problem/F
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
    ld a[8];
    for (auto& elem : a) cin >> elem;
    ld x1 = (a[0] + a[2]) / 2, y1 = (a[1] + a[3]) / 2;
    ld x2 = (a[4] + a[6]) / 2, y2 = (a[5] + a[7]) / 2;
    ld d = sqrt (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    ld r1 = (sqrt (((a[0] - a[2]) * (a[0] - a[2])) + ((a[1] - a[3]) * (a[1] - a[3])))) / 2;
    ld r2 = (sqrt (((a[4] - a[6]) * (a[4] - a[6])) + ((a[5] - a[7]) * (a[5] - a[7])))) / 2;
    if (d < r1 + r2 || fabs (d - (r1 + r2)) <= 1e-9) cout << "YES\n";
    else cout << "NO\n";
}

