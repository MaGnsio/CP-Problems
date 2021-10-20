//https://vjudge.net/contest/417978#problem/B
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
    ll d = 0, chk = 1;
    string s, t, p = "";
    cin >> s >> t;
    for (ll i = 0; i < s.size (); ++i) d += (s[i] != t[i]);
    if (d & 1) return cout << "impossible", 0;
    for (ll i = 0; i < s.size (); ++i)
    {
        if (s[i] == t[i]) p.push_back (s[i]);
        else if (s[i] != t[i])
        {
            if (chk) p.push_back (s[i]), chk = 0;
            else p.push_back (t[i]), chk = 1;
        }
    }
    cout << p;
}

