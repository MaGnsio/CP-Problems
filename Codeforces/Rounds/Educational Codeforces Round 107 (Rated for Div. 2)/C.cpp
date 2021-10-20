//https://codeforces.com/contest/1511/problem/C
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n), f(51, -1);
    for (auto& x : v) {
        cin >> x;
    }
    for (int i = 0; i < n; ++i) {
        if (f[v[i]] == -1) {
            f[v[i]] = i;
        }
    }
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << f[x] + 1 << " ";
        int idx = f[x];
        for (int j = 0; j < 51; ++j) {
            if (f[j] == -1 || j == x) continue;
            if (f[j] < idx) f[j]++;
        }
        f[x] = 0;
    }
}

