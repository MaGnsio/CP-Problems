//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/G
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
    int cnt = 0;
    int f[26] = {};
    string s;
    cin >> s;
    for (auto& x : s) f[x - 'a']++;
    for (auto& x : f) if (x & 1) cnt++;
    if ((!cnt) || (cnt & 1)) cout << "First";
    else cout << "Second";
}

