/**
 *    author:  MaGnsi0
 *    created: 31.01.2023 22:09:22
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k; k++;
    vector<vector<string>> a(k, vector<string>(n));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    function<pair<int, int>(vector<string>, vector<string>)> diff = [&](vector<string> x, vector<string> y) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (x[i][j] != y[i][j]) {
                    return make_pair(i + 1, j + 1);
                }
            }
        }
        return make_pair(0, 0);
    };
    vector<int> cnt(k, 0);
    for (int x = 0; x < k; ++x) {
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                bool ok = true;
                for (int c = 0; c < 4; ++c) {
                    int ni = i + dx[c];
                    int nj = j + dy[c];
                    ok &= a[x][i][j] != a[x][ni][nj];
                }
                cnt[x] += ok;
            }
        }
    }
    vector<int> I(k);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            return cnt[i] > cnt[j];
        });
    vector<tuple<int, int, int>> op;
    for (int i = 1; i < k; ++i) {
        pair<int, int> p = diff(a[I[i]], a[I[i - 1]]);
        if (p.first) {
            a[I[i - 1]][p.first - 1][p.second - 1] ^= '1' ^ '0';
            op.emplace_back(1, p.first, p.second);
            i--;
        } else {
            op.emplace_back(2, I[i] + 1, 0);
        }
    }
    cout << I[0] + 1 << "\n";
    cout << (int)op.size() << "\n";
    for (auto& [t, x, y] : op) {
        if (t == 1) {
            cout << t << " " << x << " " << y << "\n";
        } else {
            cout << t << " " << x << "\n";
        }
    }
}
