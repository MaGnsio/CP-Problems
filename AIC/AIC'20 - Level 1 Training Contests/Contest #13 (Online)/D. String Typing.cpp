//https://codeforces.com/group/aDFQm4ed6d/contest/286323/problem/D
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
    int n;
    string s;
    cin >> n >> s;
    int cnt = n;
    for (int i = 0; i < n / 2 + 1; ++i)
    {
        string x = s.substr (0, i);
        string y = s.substr (i, i);
        if (x == y) cnt = min (cnt, n - i + 1);
    }
    cout << cnt;
}

