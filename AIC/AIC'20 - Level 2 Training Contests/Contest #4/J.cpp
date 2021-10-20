//https://vjudge.net/contest/417537#problem/J
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll count (ll f)
{
    ll cnt = 0;
    while (f)
    {
        cnt += f / 5;
        f /= 5;
    }
    return cnt;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, x;
    cin >> n;
    for (ll i = 5; ; i += 5)
    {
        if (count (i) == n) {x = i; break;}
        if (count (i) > n) return cout << 0, 0;
    }
    cout << 5 << "\n";
    cout << x << " " << x + 1 << " " << x + 2 << " " << x + 3 << " " << x + 4;
}

