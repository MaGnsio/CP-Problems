//https://codeforces.com/problemset/problem/1367/A
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
    for (ll i = 0; i < s.size (); i += 2) cout << s[i];
    cout << s[s.size () - 1] << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

