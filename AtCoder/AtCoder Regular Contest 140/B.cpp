/**
 *    author:  MaGnsi0
 *    created: 24.05.2022 16:36:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> F(2, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        F[0][i] += s[i] == 'A';
        F[1][i] += s[i] == 'C';
    }
    for (int i = n - 2; i >= 0; --i) {
        F[0][i] += F[0][i + 1];
    }
    for (int i = 1; i < n; ++i) {
        F[1][i] += F[1][i - 1];
    }
    auto A = [&](int x) {
        int l = 0, r = x, res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (F[0][x - m] - F[0][x] == m) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    };
    auto C = [&](int x) {
        int l = 0, r = n - x - 1, res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (F[1][x + m] - F[1][x] == m) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    };
    vector<int> blocks;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            int x = min(A(i), C(i));
            if (x) {
                blocks.push_back(x);
            }
        }
    }
    cout << min(2 * (int)blocks.size(), accumulate(blocks.begin(), blocks.end(), 0));
}
