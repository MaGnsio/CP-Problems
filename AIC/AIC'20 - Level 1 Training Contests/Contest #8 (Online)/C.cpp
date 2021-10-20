//https://codeforces.com/group/aDFQm4ed6d/contest/277178/problem/C
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
    ll n, cnt = 0;
    ll f[26] = {};
    string s;
    cin >> n >> s;
    if (n > 26) return cout << -1, 0;
    for (auto& X : s) f[X - 'a']++;
    for (auto& X : f) cnt += max (X - 1, 0ll);
    cout << cnt;
}

