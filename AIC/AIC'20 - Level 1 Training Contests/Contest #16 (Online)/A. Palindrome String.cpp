//https://codeforces.com/group/aDFQm4ed6d/contest/288718/problem/A
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
    int k, cnt = 0;
    string s;
    cin >> k >> s;
    if (k > s.size ()) return cout << "NO", 0;
    if (k == s.size ()) return cout << "YES", 0;
    int f[26] = {};
    for (auto& x : s) f[x - 'a']++;
    for (auto& x : f) if (x & 1) cnt++;
    cout << (cnt <= k ? "YES" : "NO");
}

