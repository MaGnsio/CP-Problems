//https://codeforces.com/group/aDFQm4ed6d/contest/274872/problem/A
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
    string s, x;
    unordered_map<string, ll> m;
    cin >> s;
    for (ll i = 0; i <= 9; ++i)
    {
        cin >> x;
        m[x] = i;
    }
    for (ll i = 0; i < 80; i += 10)
    {
        string temb = s.substr (i, 10);
        cout << m[temb];
    }
}

