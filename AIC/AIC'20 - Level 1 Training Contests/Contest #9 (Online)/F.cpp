//https://codeforces.com/group/aDFQm4ed6d/contest/278613/problem/F
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
    ll cnt = 0;
    string s;
    cin >> s;
    s.insert (s.begin (), 'a');
    for (ll i = 1; i < s.size (); ++i) cnt += min (26 - abs (s[i] - s[i - 1]), abs (s[i] - s[i - 1]));
    cout << cnt;
}

