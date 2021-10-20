//https://codeforces.com/group/aDFQm4ed6d/contest/296501/problem/H
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
    ll a, b;
    string s = "123456789";
    vector<string> v;
    cin >> a >> b;
    for (ll i = 1; i <= 9; ++i)
    {
        for (ll l = 0, r = i - 1; r < 9; ++l, ++r)
        {
            string k = s.substr (l, i);
            if (stoll (k) >= a && stoll (k) <= b) v.push_back (k);
        }
    }
    cout << v.size () << "\n";
    for (auto& x : v) cout << x << " ";
}

