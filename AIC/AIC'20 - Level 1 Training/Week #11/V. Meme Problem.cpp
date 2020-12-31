//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/V
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll d;
    cin >> d;
    if (!d)
    {
        cout << "Y " << 0.000000000 << " " << 0.000000000 << "\n";
        return;
    }
    if (d < 4)
    {
        cout << "N\n";
        return;
    }
    ld a = (d + sqrt ((d * d) - (4 * d))) / 2;
    ld b = (d - sqrt ((d * d) - (4 * d))) / 2;
    cout << fixed << setprecision (9) << "Y " << a << " " << b << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

