//https://codeforces.com/group/aDFQm4ed6d/contest/279676/problem/G
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    string s, h;
    cin >> s >> h;
    sort (s.begin (), s.end ());
    int n = h.size () - s.size () + 1;
    size_t k = s.size ();
    for (int i = 0; i < n; ++i)
    {
        string temp = h.substr (i, k);
        sort (temp.begin (), temp.end ());
        if (temp == s)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

