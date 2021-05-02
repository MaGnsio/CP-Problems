//https://codeforces.com/contest/1499/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    string s;
    cin >> s;
    vector<int> x, y;
    for (int i = 0; i < s.size (); ++i) if (s[i] == '0') x.push_back (i);
    for (int i = 0; i < s.size (); ++i)
    {
        int l = -1;
        if (s[i] == '1') y.push_back (i);
        else
        {
            for (int j = i; j < s.size (); ++j, ++i)
            {
                if (l == -1 || s[j] == s[l]) l = j;
                else if (s[j] == '0' && s[l] == '1') y.push_back (j);
                else if (s[j] == '1' && s[l] == '0' && j + 1 < s.size () && s[j + 1] == '0') y.push_back (j);
                else l = j;
            }
        }
    }
    bool a = true, b = true;
    for (int i = 1; i < x.size (); ++i)
    {
        if (x[i - 1] + 1 >= x[i])
        {
            a = false;
            break;
        }
    }
    for (int i = 1; i < y.size (); ++i)
    {
        if (y[i - 1] + 1 >= y[i])
        {
            b = false;
            break;
        }
    }
    cout << (a || b ? "YES\n" : "NO\n");
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

