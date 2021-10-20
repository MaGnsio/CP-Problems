//https://codeforces.com/group/aDFQm4ed6d/contest/279676/problem/H
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    unordered_set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string> v(9);
    for (auto& x : v) cin >> x;
    for (auto& x : v) for (auto& y : x) if (y == '3') y = '4';
    for (auto& x : v) cout << x << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

