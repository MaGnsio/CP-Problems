/**
 *    author:  MaGnsi0
 *    created: 10.02.2022 22:47:45
**/
#include <bits/stdc++.h>

using namespace std;

bool fits(vector<int> a, vector<int> b) {
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i] >= b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<pair<vector<int>, int>> a(n, pair<vector<int>, int>(m, 0));
        for (int i = 0; i < n; ++i) {
            a[i].second = i + 1;
            for (int j = 0; j < m; ++j) {
                cin >> a[i].first[j];
            }
        }
        for (int i = 0; i < n; ++i) {
            sort(a[i].first.begin(), a[i].first.end());
        }
        sort(a.begin(), a.end());
        vector<int> dp(n, 1), p(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (fits(a[j].first, a[i].first) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                }
            }
        }
        int res = *max_element(dp.begin(), dp.end());
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == res) {
                int j = i;
                b.push_back(a[j].second);
                while (p[j] != -1) {
                    b.push_back(a[p[j]].second);
                    j = p[j];
                }
                break;
            }
        }
        reverse(b.begin(), b.end());
        cout << res << "\n";
        for (int i = 0; i < res; ++i) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
}
