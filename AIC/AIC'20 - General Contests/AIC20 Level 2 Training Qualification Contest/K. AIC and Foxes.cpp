//https://codeforces.com/group/nVgev28wQI/contest/308101/problem/K
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
    ll n;
    string s, k = "fox";
    cin >> n >> s;
    if (n < 3)
    {
        cout << s;
        return 0;
    }
    for (ll i = 0; i < s.size () -  2; ++i)
    {
        if (s.substr (i, 3) == k)
        {
            s.erase (i, 3);
            if (s.size () < 3) break;
            i -= 3;
            if (i < -1) i = -1;
        }
    }
    if (!s.empty ()) cout << s;
}

