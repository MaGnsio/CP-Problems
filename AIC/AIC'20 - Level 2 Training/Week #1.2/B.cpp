//https://vjudge.net/contest/416254#problem/B
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
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort (a, a + 3);
    if (a[0] + a[1] > a[2])
    {
        ld p = (a[0] + a[1] + a[2]) / 2;
        ld area = sqrt ((p) * (p - a[0]) * (p - a[1]) * (p - a[2]));
        cout << "Valid\n" << fixed << setprecision (6) << area;
    }
    else cout << "Invalid";
}

