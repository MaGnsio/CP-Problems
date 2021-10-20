//https://codeforces.com/group/aDFQm4ed6d/contest/274872/problem/I
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll chk (string s, string w)
{
    ll cnt = 0;
    for (ll i = 0; i < s.size (); ++i)
    {
        if (w[i] != s[i])
        {
            ll x = w[i] - s[i];
            if (x < 0) return -1;
            else cnt += x;
        }
    }
    return cnt;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll c = LLONG_MAX;
    string s, w, a;
    cin >> s >> w;
    if (w.size () > s.size ()) return cout << -1, 0;
    for (ll i = 0; i < s.size () - w.size () + 1; ++i)
    {
        string temp = s.substr (i, w.size ());
        ll x = chk (temp, w);
        if (x != -1 && x < c) c = x, a = temp;
    }
    if (c == LLONG_MAX) cout << -1;
    else cout << a;
}

