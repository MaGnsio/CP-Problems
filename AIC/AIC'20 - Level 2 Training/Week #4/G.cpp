//https://vjudge.net/contest/433102#problem/G
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, ans = INT_MAX;
    cin >> n;
    vector<int> v (n);
    for (auto& x : v) {
        cin >> x;
    }
    for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
        int x = 0, y = 0;
        for (int j = 0; j < n; ++j) {
            x |= v[j];
            if (j == n - 1 || (mask >> j) & 1) y ^= x, x = 0;
        }
        ans = min (ans, y);
    }
    cout << ans;
}

