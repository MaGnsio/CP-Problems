//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/D
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
    int q, m = 0;
    string s;
    cin >> s >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        k %= (r - l + 1);
        if (k == 0) continue;
        string x = s.substr (l - 1, r - l - k + 1), y = s.substr (r - k, k);
        int i = l - 1;
        for (int j = 0; j < y.size (); ++j, ++i) s[i] = y[j];
        for (int j = 0; j < x.size (); ++j, ++i) s[i] = x[j];
    }
    cout << s;
}

