/**
 *    author:  MaGnsi0
 *    created: 19.09.2024 18:54:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (count(a.begin(), a.end(), -1) == n) {
            for (int i = 0; i < n; ++i) {
                cout << (i & 1 ? 1 : 2) << " ";
            }
            cout << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) { continue; }
            for (int j = i - 1; j >= 0; --j) {
                if (a[j + 1] > 1) {
                    a[j] = a[j + 1] / 2;
                } else {
                    a[j] = a[j + 1] * 2;
                }
            }
            break;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == -1) { continue; }
            for (int j = i + 1; j < n; ++j) {
                if (a[j - 1] > 1) {
                    a[j] = a[j - 1] / 2;
                } else {
                    a[j] = a[j - 1] * 2;
                }
            }
            break;
        }
        function<vector<int>(int, int, int)> solve = [&](int x, int y, int m) {
            if (x == y) {
                if (m % 2 == 0) {
                    return vector<int>(1, -1);
                }
                vector<int> res(1, x * 2);
                for (int i = 0; i < m - 1; i += 2) {
                    res.push_back(x);
                    res.push_back(x * 2);
                }
                return res;
            }
            vector<int> path_x, path_y;
            for (int x_ = x, y_ = y; x_ != y_; /*_*/) {
                if (x_ > y_) {
                    x_ /= 2;
                    if (y_ == x_) { break; }
                    path_x.push_back(x_);
                } else {
                    y_ /= 2;
                    if (y_ == x_) { break; }
                    path_y.push_back(y_);
                }
            }
            reverse(path_y.begin(), path_y.end());
            vector<int> res;
            for (int x_ : path_x) { res.push_back(x_); }
            for (int y_ : path_y) { res.push_back(y_); }
            if ((m < (int)res.size()) || ((m - (int)res.size()) & 1)) {
                return vector<int>(1, -1);
            }
            if ((int)res.empty()) {
                res.push_back(x * 2);
                res.push_back(x);
            }
            while ((int)res.size() != m) {
                res.push_back(res.back() * 2);
                res.push_back(res.back() / 2);
            }
            return res;
        };
        bool good = true;
        for (int i = -1, j = 0; j < n; ++j) {
            if (a[j] == -1) { continue; }
            if (i + 1 != j) {
                vector<int> b = solve(a[i], a[j], j - i - 1);
                if (b[0] == -1) {
                    good = false;
                    break;
                }
                for (int k = i + 1; k < j; ++k) {
                    a[k] = b[k - (i + 1)];
                }
            }
            i = j;
        }
        if (good) {
            for (int i = 0; i + 1 < n; ++i) {
                if (a[i] / 2 == a[i + 1]) { continue; }
                if (a[i + 1] / 2 == a[i]) { continue; }
                good = false;
                break;
            }
        }
        if (good) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
        } else {
            cout << -1;
        }
        cout << "\n";
    }
}
