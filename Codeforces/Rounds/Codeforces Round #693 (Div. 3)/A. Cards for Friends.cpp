//https://codeforces.com/contest/1472/problem/A
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
        ll w, h, n, cnt = 1, p = 1;
        cin >> w >> h >> n;
        while ((w % 2 == 0) || (h % 2 == 0))
        {
            if (w % 2 == 0) cnt += p, w /= 2, p *= 2;
            if (h % 2 == 0) cnt += p, h /= 2, p *= 2;
        }
        if (cnt >= n) cout << "YES\n";
        else cout << "NO\n";
    }
}
