/**
 *    author:  MaGnsi0
 *    created: 12.02.2022 14:55:10
**/
#include <bits/stdc++.h>

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    int x = x1 - x2;
    int y = y1 - y2;
    return double(sqrt((1LL * x * x) + (1LL * y * y)));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> X, Y;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (!y) {
            X.push_back(x);
        }
        if (!x) {
            Y.push_back(y);
        }
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    double res = 0.0;
    if (X.size() > 1) {
        res = max(res, double(X[X.size() - 1] - X[0]));
    }
    if (Y.size() > 1) {
        res = max(res, double(Y[Y.size() - 1] - Y[0]));
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x = (i == 2 ? (int)X.size() - 1 : i);
            int y = (j == 2 ? (int)Y.size() - 1 : j);
            if (x >= X.size() || y >= Y.size()) {
                continue;
            }
            if (!X[x] && !Y[y]) {
                continue;
            }
            res = max(res, dist(X[x], 0, 0, Y[y]));
        }
    }
    cout << fixed << setprecision(6) << res;
}
