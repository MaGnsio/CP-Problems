/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 20:30:46
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 7, M = 8;

short dp[N][N][N][N][N][N][N], A[N][M];

int check(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int i, int j) {
    int res = 0;
    int l[M] = {0, c1, c2, c3, c4, c5, c6, c7};
    //row
    for (int start = max(j - 3, 1); start < min(j + 4, M) && start + 3 < M; ++start) {
        int x = 0;
        for (int col = start; col < start + 4; ++col) {
            x += i > l[col] && A[i][col] == A[i][j];
        }
        if (x == 4) { return A[i][j]; }
    }
    //diagonal
    {
        int x = 0;
        for (int k = 0; k < 4; ++k) {
            x += i + k < N && j + k < M && i + k > l[j + k] && A[i + k][j + k] == A[i][j];
        }
        if (x == 4) { return A[i][j]; }
    }
    {
        int x = 0;
        for (int k = 0; k < 4; ++k) {
            x += i + k < N && 0 < j - k && i + k > l[j - k] && A[i + k][j - k] == A[i][j];
        }
        if (x == 4) { return A[i][j]; }
    }
    //col
    {
        int x = 0;
        for (int k = 0; k < 4; ++k) {
            x += i + k < N && i + k > l[j] && A[i + k][j] == A[i][j];
        }
        if (x == 4) { return A[i][j]; }
    }
    return res;
}

short solve(int c1, int c2, int c3, int c4, int c5, int c6, int c7) {
    if (!c1 && !c2 && !c3 && !c4 && !c5 && !c6 && !c7) { return 0; }
    short& res = dp[c1][c2][c3][c4][c5][c6][c7];
    if (res != -1) { return res; }
    res = 0;
    if (c1) {
        int val = check(c1 - 1, c2, c3, c4, c5, c6, c7, c1, 1);
        if (val) {
            res |= val;
        } else {
            res |= solve(c1 - 1, c2, c3, c4, c5, c6, c7);
        }
    }
    if (c2) {
        int val = check(c1, c2 - 1, c3, c4, c5, c6, c7, c2, 2);
        if (val) {
            res |= val;
        } else {
            res |= solve(c1, c2 - 1, c3, c4, c5, c6, c7);
        }
    }
    if (c3) {
        int val = check(c1, c2, c3 - 1, c4, c5, c6, c7, c3, 3);
        if (val) {
            res |= val;
        } else {
            res |= solve(c1, c2, c3 - 1, c4, c5, c6, c7);
        }
    }
    if (c4) {
        int val = check(c1, c2, c3, c4 - 1, c5, c6, c7, c4, 4);
        if (val) {
            res |= val;
        } else {
            res |= solve(c1, c2, c3, c4 - 1, c5, c6, c7);
        }
    }
    if (c5) {
        int val = check(c1, c2, c3, c4, c5 - 1, c6, c7, c5, 5);
        if (val) {
            res |= val;
        } else {
            res |= solve(c1, c2, c3, c4, c5 - 1, c6, c7);
        }
    }
    if (c6) {
        int val = check(c1, c2, c3, c4, c5, c6 - 1, c7, c6, 6);
        if (val) {
            res |= val;
        } else {
            res |= solve(c1, c2, c3, c4, c5, c6 - 1, c7);
        }
    }
    if (c7) {
        int val = check(c1, c2, c3, c4, c5, c6, c7 - 1, c7, 7);
        if (val) {
            res |= val;
        } else {
            res |= solve(c1, c2, c3, c4, c5, c6, c7 - 1);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        memset(dp, -1, sizeof dp);
        cout << "Case #" << t << ": ";
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                char c; cin >> c;
                A[i][j] = c == 'C' ? 1 : 2;
            }
        }
        int p = solve(N - 1, N - 1, N - 1, N - 1, N - 1, N - 1, N - 1);
        cout << (p == 0 ? '0' : (p == 1 ? 'C' : (p == 2 ? 'F' : '?'))) << "\n";
    }
}
