/**
 *    author:  MaGnsi0
 *    created: 24.05.2022 16:28:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = n;
    auto can = [&](int x) {
        vector<vector<int>> f(x, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            f[i % x][s[i] - 'a']++;
        }
        int changes = 0;
        for (int i = 0; i < x; ++i) {
            changes += accumulate(f[i].begin(), f[i].end(), 0) - *max_element(f[i].begin(), f[i].end());
        }
        return (changes <= k);
    };
    for (int i = n - 1; i >= 1; --i) {
        if (n % i == 0 && can(i)) {
            ans = i;
        }
    }
    cout << ans << "\n";
}
