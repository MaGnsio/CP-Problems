//https://codeforces.com/group/aDFQm4ed6d/contest/287686/problem/A
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
    int n, k, i, cnt = 0;
    cin >> n >> k;
    int a[n];
    for (auto& x : a) cin >> x;
    for (i = 0; i < n; ++i, ++cnt) if (a[i] > k) break;
    for (int j = n - 1; j > i; --j, ++cnt) if (a[j] > k) break;
    cout << cnt;
}

