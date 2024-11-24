/**
 *    author:  MaGnsi0
 *    created: 24.11.2024 21:43:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> b(3);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            b[0].push_back(i);
        } else if (s[i] == '2') {
            b[1].push_back(i);
        } else {
            b[2].push_back(i);
        }
    }
    int ans = 1;
    for (int j : b[2]) {
        int R = n;
        {
            auto it = upper_bound(b[0].begin(), b[0].end(), j);
            if (it != b[0].end()) {
                R = min(R, *it);
            }
        }
        {
            auto it = upper_bound(b[2].begin(), b[2].end(), j);
            if (it != b[2].end()) {
                R = min(R, *it);
            }
        }
        int L = -1;
        {
            auto it = lower_bound(b[1].begin(), b[1].end(), j);
            if (it != b[1].begin()) {
                it--;
                L = max(L, *it);
            }
        }
        {
            auto it = lower_bound(b[2].begin(), b[2].end(), j);
            if (it != b[2].begin()) {
                it--;
                L = max(L, *it);
            }
        }
        ans = max(ans, 2 * min(R - j - 1, j - L - 1) + 1);
    }
    cout << ans;
}
