//https://codeforces.com/contest/1494/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    string a;
    cin >> a;
    char b[a.size ()], c[a.size ()];
    for (int i = 0; i < a.size (); ++i)
    {
        if (a[i] == a[0]) b[i] = c[i] = '(';
        else if (a[i] == a[a.size () - 1]) b[i] = c[i] = ')';
        else b[i] = '(', c[i] = ')';
    }
    bool chk1 = true, chk2 = true;
    stack<char> s1, s2;
    for (int i = 0; i < a.size (); ++i)
    {
        if (b[i] == '(') s1.push (b[i]);
        else if (!s1.empty ()) s1.pop ();
        else chk1 = false;
        if (c[i] == '(') s2.push (c[i]);
        else if (!s2.empty ()) s2.pop ();
        else chk2 = false;
    }
    if (!s1.empty ()) chk1 = false;
    if (!s2.empty ()) chk2 = false;
    cout << (chk1 || chk2 ? "YES\n" : "NO\n");
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

