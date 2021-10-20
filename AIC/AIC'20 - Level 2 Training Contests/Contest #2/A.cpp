//https://vjudge.net/contest/415649#problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

string ims (string s)
{
    string x = s;
    reverse (x.begin (), x.end ());
    if (x != s) return "no";
    for (ll i = 0; i < x.size (); ++i)
    {
        if (x[i] == 'A' || x[i] == 'H'
         || x[i] == 'I' || x[i] == 'M'
         || x[i] == 'O' || x[i] == 'T'
         || x[i] == 'U' || x[i] == 'V'
         || x[i] == 'W' || x[i] == 'X' || x[i] == 'Y') continue;
        return "no";
    }
    return "yes";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << ims (s) << "\n";
    }
}

