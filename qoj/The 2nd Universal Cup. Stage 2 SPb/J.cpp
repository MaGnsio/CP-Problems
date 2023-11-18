/**
 *    author:  MaGnsi0
 *    created: 14.10.2023 11:44:38
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 101;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

double D(int x1, int y1, int x2, int y2) {
    double dx = (x1 - x2);
    double dy = (y1 - y2);
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int t; cin >> t;
    vector<int> x(2), y(2);
    for (int i = 0; i < 2; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }
    set<tuple<double, int, int>> S;
    vector<vector<int>> portal(N, vector<int>(N));
    vector<vector<bool>> done(N, vector<bool>(N, false));
    vector<vector<double>> d(N, vector<double>(N, 1e9));
    vector<vector<pair<int, int>>> p(N, vector<pair<int, int>>(N, {-1, -1}));
    d[x[0]][y[0]] = 0.0;
    while (true) {
        int xv = -1, yv = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (done[i][j]) { continue; }
                if (xv == -1 || d[i][j] < d[xv][yv]) {
                    xv = i, yv = j;
                }
            }
        }
        if (xv == -1 || d[xv][yv] == 1e9) { break; }
        done[xv][yv] = true;
        double dv = d[xv][yv];
        if (dv + D(xv, yv, x[1], y[1]) < d[x[1]][y[1]]) {
            portal[x[1]][y[1]] = 0;
            d[x[1]][y[1]] = dv + D(xv, yv, x[1], y[1]);
            p[x[1]][y[1]] = {xv, yv};
            done[x[1]][y[1]] = false;
        }
        for (int i = 0; i < n; ++i) {
            if (xv != X[i] && yv != Y[i]) { continue; }
            if (dv + t < d[x[1]][Y[i]]) {
                portal[x[1]][Y[i]] = i + 1;
                d[x[1]][Y[i]] = dv + t;
                p[x[1]][Y[i]] = {xv, yv};
                done[x[1]][Y[i]] = false;
            }
            if (dv + t < d[X[i]][y[1]]) {
                portal[X[i]][y[1]] = i + 1;
                d[X[i]][y[1]] = dv + t;
                p[X[i]][y[1]] = {xv, yv};
                done[X[i]][y[1]] = false;
            }
            if (x[1] == X[i] || y[1] == Y[i]) {
                if (dv + t < d[x[1]][y[1]]) {
                    portal[x[1]][y[1]] = i + 1;
                    d[x[1]][y[1]] = dv + t;
                    p[x[1]][y[1]] = {xv, yv};
                    done[x[1]][y[1]] = false;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (i == j) { continue; }
                if (dv + t < d[X[j]][Y[i]]) {
                    portal[X[j]][Y[i]] = i + 1;
                    d[X[j]][Y[i]] = dv + t;
                    p[X[j]][Y[i]] = {xv, yv};
                    done[X[j]][Y[i]] = false;
                }
                if (dv + t < d[X[i]][Y[j]]) {
                    portal[X[i]][Y[j]] = i + 1;
                    d[X[i]][Y[j]] = dv + t;
                    p[X[i]][Y[j]] = {xv, yv};
                    done[X[i]][Y[j]] = false;
                }
                if (X[j] == X[i] || Y[j] == Y[i]) {
                    if (dv + t < d[X[j]][Y[j]]) {
                        portal[X[j]][Y[j]] = i + 1;
                        d[X[j]][Y[j]] = dv + t;
                        p[X[j]][Y[j]] = {xv, yv};
                        done[X[j]][Y[j]] = false;
                    }
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            int xu = xv + dx[i];
            int yu = yv + dy[i];
            if (xu < 0 || xu >= N) { continue; }
            if (yu < 0 || yu >= N) { continue; }
            if (d[xu][yu] <= dv + 1) { continue; }
            portal[xu][yu] = 0;
            d[xu][yu] = dv + 1;
            p[xu][yu] = {xv, yv};
            done[xu][yu] = false;
        }
    }
    cout << fixed << setprecision(6) << d[x[1]][y[1]] << "\n";
    int x_ = x[1], y_ = y[1];
    vector<tuple<int, int, int>> ans;
    while (!(x_ == x[0] && y_ == y[0])) {
        ans.emplace_back(portal[x_][y_], x_, y_);
        pair<int, int> p_ = p[x_][y_];
        x_ = p_.first, y_ = p_.second;
    }
    reverse(ans.begin(), ans.end());
    cout << (int)ans.size() << "\n";
    for (auto [portal, x_, y_] : ans) {
        cout << portal << " " << x_ << " " << y_ << "\n";
    }
}
