//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/H
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) if (2 * i >= n && i % m == 0) return cout << i, 0;
    cout << -1;
}

