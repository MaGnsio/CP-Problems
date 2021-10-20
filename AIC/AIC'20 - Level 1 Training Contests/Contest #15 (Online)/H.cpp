//https://codeforces.com/group/aDFQm4ed6d/contest/287686/problem/H
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
    int n, t, c = INT_MAX;
    cin >> n;
    int a[n];
    for (auto& x : a) cin >> x;
    for (int i = 1; i <= 100; ++i)
    {
        int cnt = 0;
        for (auto& x : a) cnt += max (0, abs (x - i) - 1);
        if (cnt < c) t = i, c = cnt;
    }
    cout << t << " " << c;
}

