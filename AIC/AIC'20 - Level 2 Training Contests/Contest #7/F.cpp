//https://vjudge.net/contest/421809#problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);cin.sync();
    ll t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        ll idx = 0;
        stack<char> s;
        string x, y;
        getline (cin, x);
        getline (cin, y);
        for (ll i = 0; i < x.size (); ++i)
        {
            if (y.size () && x[i] == y[idx])
            {
                s.push (x[i]);
                if (idx == y.size () - 1) idx = 0;
                else idx++;
            }
        }
        ll ans = x.size () - (y.size () ? (s.size () / y.size ()) * y.size () : 0);
        cout << ans << "\n";
    }
}

