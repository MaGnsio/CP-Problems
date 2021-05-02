//https://codeforces.com/contest/1472/problem/B
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
        ll n, x, cnt1 = 0, cnt2 = 0;
        cin >> n;
        for (ll i = 0; i < n; ++i)
        {
            cin >> x;
            if (x == 1) cnt1++;
            else cnt2++;
        }
        if ((cnt1 + (2 * cnt2)) % 2 == 0 && (((cnt1 + (2 * cnt2)) / 2) % 2 == 0 || cnt1)) cout << "YES\n";
        else cout << "NO\n";
    }
}
