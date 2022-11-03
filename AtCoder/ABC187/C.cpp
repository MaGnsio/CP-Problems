//https://atcoder.jp/contests/abc187/tasks/abc187_c
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
    cin >> n;
    map<string, pair<int, int>> m;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (s[0] != '!') m[s].F = 1;
        else m[s.substr (1)].S = 1;
    }
    for (auto& x : m) if (x.S.F && x.S.S)
            return cout << x.F, 0;
    cout << "satisfiable";
}
