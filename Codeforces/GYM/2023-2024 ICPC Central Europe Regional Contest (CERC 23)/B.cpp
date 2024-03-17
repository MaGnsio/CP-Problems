/**
 *    author:  MaGnsi0
 *    created: 13.01.2024 13:59:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<double>> X(2), Y(2);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int y; cin >> y;
        if (s[i] == 'B') {
            X[0].push_back(x);
            Y[0].push_back(y);
        } else {
            X[1].push_back(x);
            Y[1].push_back(y);
        }
    }
    function<double(int, int, int)> D = [&](int t, int i, int j) {
        double dx = X[t][i] - X[t][j];
        double dy = Y[t][i] - Y[t][j];
        return sqrt(dx * dx + dy * dy);
    };
    double ans = 0;
    for (int i = 0; i < 2; ++i) {
        int m = (int)X[i].size();
        for (int j = 0; j < m / 2; ++j) {
            ans += D(i, j, j + m / 2);
        }
    }
    cout << fixed << setprecision(10) << ans;
}
