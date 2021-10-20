//https://codeforces.com/group/Rv2Qzg0DgK/contest/273155/problem/H
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
    int n, m, l, r;
    cin >> n >> m;
    vector<int> v(m + 1), a;
    while (n--)
    {
        cin >> l >> r;
        v[l - 1]++, v[r]--;
    }
    for (int i = 1; i < m + 1; ++i) v[i] += v[i - 1];
    for (int i = 0; i < m; ++i) if (!v[i]) a.push_back (i + 1);
    cout << a.size () << "\n";
    for (auto& elem : a) cout << elem << " ";
}

