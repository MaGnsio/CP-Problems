//https://codeforces.com/group/aDFQm4ed6d/contest/288718/problem/C
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, m = 1ll << 32;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll l, x = 0;
    cin >> l;
    stack<ll> s;
    s.push (1);
    while (l--)
    {
        string t;
        cin >> t;
        if (t == "for")
        {
            ll k;
            cin >> k;
            s.push (min (m, s.top () * k));
        }
        else if (t == "end") s.pop ();
        else x += s.top ();
    }
    if (x >= m) cout << "OVERFLOW!!!";
    else cout << x;
}

