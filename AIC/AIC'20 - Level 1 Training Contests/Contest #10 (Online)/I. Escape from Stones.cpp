//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/I
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    cin >> s;
    for (ll i = 0; i < s.size (); ++i) if (s[i] == 'r') cout << i + 1 << "\n";
    for (ll i = s.size () - 1; i >= 0; --i) if (s[i] == 'l') cout << i + 1 << "\n";
}

