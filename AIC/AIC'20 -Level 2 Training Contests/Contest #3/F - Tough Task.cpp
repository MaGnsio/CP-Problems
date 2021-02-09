//https://vjudge.net/contest/416541#problem/F
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
    ld t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (a == 1 && d == 1) cout << "=";
        else if (a == 1) cout << "<";
        else if (d == 1) cout << ">";
        else
        {
            ld g = c * log (b) + log (log (a));
            ld h = log (e) + log (log (d));
            if (g > h + 1e-9) cout << ">";
            else if (g + 1e-9 < h) cout << "<";
            else cout << "=";
        }
        cout << "\n";
    }
}

