//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/U
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ld sqrt_bs (ld n)
{
    ld l = 0, m, r = n, ep = 1e-9; //shifting unit is equal 1e-9 "not 1 as usaul"
    while (l <= r)
    {
        m = (l + r) / 2.0;
        if (fabs (m * m - n) <= ep) return m;
        if (m * m >= n) r = m - ep;
        else l = m + ep;
    }
    return m;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ld n;
    cin >> n;
    cout << fixed << setprecision (9) << sqrt_bs (n);
}

