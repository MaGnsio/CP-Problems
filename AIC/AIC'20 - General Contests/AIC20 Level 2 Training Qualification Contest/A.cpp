//https://codeforces.com/group/nVgev28wQI/contest/308101/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if ((s[s.size () - 1] - '0') & 1) cout << -1 << "\n";
        else cout << 1 << "\n";
    }
}

