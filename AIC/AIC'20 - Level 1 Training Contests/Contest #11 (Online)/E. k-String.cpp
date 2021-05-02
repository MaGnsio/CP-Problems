//https://codeforces.com/group/aDFQm4ed6d/contest/279676/problem/E
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
    int k;
    int f[26] = {};
    string s, t = "";
    cin >> k >> s;
    if (s.size () % k != 0) return cout << -1, 0;
    for (auto& x : s) f[x - 'a']++;
    for (int i = 0; i < 26; ++i)
    {
        if (f[i] % k != 0) return cout << -1, 0;
        for (int j = 0; j < f[i] / k; ++j) t.push_back ('a' + i);
    }
    for (int i = 0; i < k; ++i) cout << t;
}

