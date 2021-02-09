//https://codeforces.com/group/aDFQm4ed6d/contest/277178/problem/D
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
        ll n, m, cnt = 0, p = 0;
        string s;
        cin >> n >> m >> s;
        for (ll i = 0; i < n / 2; ++i) if (s[i] != s[n - 1 - i]) p++;
        while (m--)
        {
            ll idx;
            char c;
            cin >> idx >> c;
            if ((s.size () & 1) && (idx - 1 == n / 2))
            {
                if (!p) cnt++;
                continue;
            }
            if (s[idx - 1] != c)
            {
                if (s[idx - 1] == s[n - idx])
                {
                    p++;
                    s[idx - 1] = c;
                }
                else
                {
                    s[idx - 1] = c;
                    if (s[idx - 1] == s[n - idx]) p--;
                }
            }
            if (!p) cnt++;
        }
        cout << cnt << "\n";
    }
}

