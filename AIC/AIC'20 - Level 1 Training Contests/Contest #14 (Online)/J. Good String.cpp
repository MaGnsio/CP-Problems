//https://codeforces.com/group/aDFQm4ed6d/contest/287062/problem/J
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        string s;
        cin >> n >> s;
        for (i = 0; i < n; ++i) if (s[i] == '>') break;
        for (j = n - 1; j >= 0; --j) if (s[j] == '<') break;
        cout << min (i, n - 1 - j) << "\n";
    }
}

