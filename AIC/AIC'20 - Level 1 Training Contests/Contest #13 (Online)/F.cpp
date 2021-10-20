//https://codeforces.com/group/aDFQm4ed6d/contest/286323/problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (s == t)
    {
        cout << "Yes\n";
        return;
    }
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] != t[i]) v.push_back (i);
        if (v.size () == 2) break;
    }
    if (v.size () < 2)
    {
        cout << "No\n";
        return;
    }
    swap (s[v[0]], t[v[1]]);
    cout << (s == t ? "Yes\n" : "No\n");
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

