//https://codeforces.com/group/aDFQm4ed6d/contest/274872/problem/B
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
        ll n, i = 0, ans = 0;
        string s;
        cin >> n >> s;
        for (; i < n; ++i) if (s[i] == 'A') break;
        for (; i < n; ++i)
        {
            ll temp = 0;
            while (s[i] == 'P' && i < n) i++, temp++;
            ans = max (ans, temp);
        }
        cout << ans << "\n";
    }
}

