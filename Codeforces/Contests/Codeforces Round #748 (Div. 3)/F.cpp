/**
 *    author:  MaGnsi0
 *    created: 14.10.2021 17:35:56
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 41;

int n, A, B;
int dp[N][N][N][2 * N];
string x;

int solve(int i, int j, int k, int d) {
    if (k == n) {
        if (i || j) {
            return n;
        } else {
            return abs(d);
        }
    }
    int& ans = dp[i][j][k][d + n];
    if (ans != -1) {
        return ans;
    }
    int c = x[k] - '0';
    ans = min(solve((i * 10 + c) % A, j, k + 1, d + 1), solve(i, (j * 10 + c) % B, k + 1, d - 1));
    return ans;
}

void build(int i, int j, int k, int d) {
    if (k == n) {
        return;
    }
    int c = x[k] - '0';
    if (solve((i * 10 + c) % A, j, k + 1, d + 1) < solve(i, (j * 10 + c) % B, k + 1, d - 1)) {
        cout << "R";
        build((i * 10 + c) % A, j, k + 1, d + 1);
    } else {
        cout << "B";
        build(i, (j * 10 + c) % B, k + 1, d - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> A >> B >> x;
        memset(dp, -1, sizeof dp);
        if (solve(0, 0, 0, 0) == n) {
            cout << "-1\n";
        } else {
            build(0, 0, 0, 0);
            cout << "\n";
        }
    }
}
