/**
 *    author:  MaGnsi0
 *    created: 11.09.2022 17:54:47
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const double OO = 1e15;

int n, b1, b2;
int X[N], Y[N];
double dp[N][N][N][2][2];
bool done[N][N][N][2][2];

double D(int i, int j) {
    return sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
}

double solve(int i, int j, int k, int x, int y) {
    if (i == n - 1) {
        return (x && y ? D(i, j) + D(i, k) : OO);
    }
    double& res = dp[i][j][k][x][y];
    if (done[i][j][k][x][y]) {
        return res;
    }
    done[i][j][k][x][y] = true;
    res = D(i, j) + solve(i + 1, i, k, (x || i == b1 || i == b2), y);
    res = min(res, D(i, k) + solve(i + 1, j, i, x, (y || i == b1 || i == b2)));
    return res;
}

vector<int> go, back;

void build(int i, int j, int k, int x, int y) {
    if (i == n - 1) {
        return;
    }
    double res1 = D(i, j) + solve(i + 1, i, k, (x || i == b1 || i == b2), y);
    double res2 = D(i, k) + solve(i + 1, j, i, x, (y || i == b1 || i == b2));
    if (isless(res1, res2)) {
        go.push_back(i);
        build(i + 1, i, k, (x || i == b1 || i == b2), y);
    } else {
        back.push_back(i);
        build(i + 1, j, i, x, (y || i == b1 || i == b2));
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    while ((cin >> n >> b1 >> b2) && (n + b1 + b2)) {
        memset(dp, -1, sizeof dp);
        memset(done, 0, sizeof done);
        go.clear(), back.clear();
        for (int i = 0; i < n; ++i) {
            cin >> X[i] >> Y[i];
        }
        build(1, 0, 0, 0, 0);
        if (back[0] == 1) {
            swap(go, back);
        }
        go.insert(go.begin(), 0);
        go.push_back(n - 1);
        back.insert(back.begin(), 0);
        reverse(back.begin(), back.end());
        cout << "Case " << T++ << ": ";
        cout << fixed << setprecision(2) << solve(1, 0, 0, 0, 0) << "\n";
        for (int i = 0; i < (int)go.size(); ++i) {
            cout << go[i] << " ";
        }
        for (int i = 0; i < (int)back.size(); ++i) {
            cout << back[i];
            if (i < (int)back.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
