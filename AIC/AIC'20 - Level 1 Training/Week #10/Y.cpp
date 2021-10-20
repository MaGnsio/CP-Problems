//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/Y
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
    int n, mx = 0;
    map<string, int> m, k;
    cin >> n;
    int a[n];
    string b[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i] >> a[i];
        m[b[i]] += a[i];
    }
    for (auto& x : m) mx = max (mx, x.S);
    for (int i = 0; i < n; ++i)
    {
        k[b[i]] += a[i];
        if (k[b[i]] >= mx && m[b[i]] == mx) return cout << b[i], 0;
    }
}

