/**
 *    author:  MaGnsi0
 *    created: 12.09.2023 21:56:27
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 105;

string S, A, B, C;
int N, dp[M][3][2][2][2][2];

int solve(int x, int y, int z, int u, int v, int w) {
    if (x == N) { return y == 0; }
    int& ans = dp[x][y][z][u][v][w];
    if (ans != -1) { return ans; }
    ans = 0;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            int k = (S[x] - '0' - (i + j + y) % 10 + 10) % 10;
            if (i == 1 || j == 1 || k == 1) { continue; }
            if ((u && i) || (v && j) || (w && k)) { continue; }
            int y_ = (i + j + k + y) / 10;
            int z_ = (z && k == 0);
            int u_ = (u || i == 0);
            int v_ = (v || j == 0);
            int w_ = (w || k == 0);
            ans |= solve(x + 1, y_, z_, u_, v_, w_);
        }
    }
    return ans;
}

void build(int x, int y, int z, int u, int v, int w) {
    if (x == N) { return; }
    for (int want = 1; want <= 2; ++want) {
        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j <= 9; ++j) {
                int k = (S[x] - '0' - (i + j + y) % 10 + 10) % 10;
                if (i == 1 || j == 1 || k == 1) { continue; }
                if ((u && i) || (v && j) || (w && k)) { continue; }
                int y_ = (i + j + k + y) / 10;
                int z_ = (z && k == 0);
                int u_ = (u || i == 0);
                int v_ = (v || j == 0);
                int w_ = (w || k == 0);
                if (z_ != want % 2) { continue; }
                if (solve(x + 1, y_, z_, u_, v_, w_) == 0) { continue; }
                A += char(i + '0'), B += char(j + '0'), C += char(k + '0');
                build(x + 1, y_, z_, u_, v_, w_);
                goto next;
            }
        }
    }
    next:
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> S;
        A = B = C = "";
        N = (int)S.size();
        memset(dp, -1, sizeof dp);
        reverse(S.begin(), S.end());
        build(0, 0, 1, 0, 0, 0);
        while (!A.empty() && A.back() == '0') { A.pop_back(); }
        while (!B.empty() && B.back() == '0') { B.pop_back(); }
        while (!C.empty() && C.back() == '0') { C.pop_back(); }
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        reverse(C.begin(), C.end());
        int ans = 3 - (C == "");
        cout << ans << "\n";
        cout << A << " " << B << " " << C << "\n";
    }
}
