//https://codeforces.com/group/aDFQm4ed6d/contest/279676/problem/J
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    int a = 0, b = 0;
    string t;
    cin >> t;
    for (auto& x : t) a += (x == '0'), b += (x == '1');
    if (!a || !b)
    {
        cout << t << "\n";
        return;
    }
    string s = "";
    for (int i = 0; i < t.size () - 1; ++i)
    {
        s.push_back (t[i]);
        if (t[i] == t[i + 1])
        {
            if (t[i] == '0') s.push_back ('1');
            else s.push_back ('0');
        }
    }
    s.push_back (t[t.size () - 1]);
    cout << s << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}
