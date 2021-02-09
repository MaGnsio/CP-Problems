//https://vjudge.net/contest/415649#problem/J
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
        ll c, n;
        ld a, ans = 0;
        string s;
        unordered_map<string, ld> m;
        cin >> c >> n;
        for (ll i = 0; i < c; ++i)
        {
            cin >> s >> a;
            m[s] = a;
        }
        while (n--)
        {
            cin >> a >> s;
            if (s == "JD") ans += a;
            else ans += (a * m[s]);
        }
        cout << fixed << setprecision (6) << ans << "\n";
    }
}

