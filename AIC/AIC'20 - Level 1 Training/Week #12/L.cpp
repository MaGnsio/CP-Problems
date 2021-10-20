//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/L
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, cur = 0, p1 = 0, p2 = 0, m = 0;
    bool t = 1;
    cin >> n;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    for (ll i = 0, j = n - 1; i <= j; t = !t)
    {
        ll temb = 0;
        if (t)
        {
            while (i <= j && temb <= cur) temb += a[i++];
            cur = temb;
            p1 += temb;
            m++;
        }
        else
        {
            while (i <= j && temb <= cur) temb += a[j--];
            cur = temb;
            p2 += temb;
            m++;
        }
    }
    cout << m << " " << p1 << " " << p2 << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

