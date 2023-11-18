/**
 *    author:  MaGnsi0
 *    created: 21.10.2023 20:36:21
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 3e6;
const array<int64_t, 2> B = {31, 53};
const array<int64_t, 2> MOD = {int64_t(1e9 + 7), int64_t(1e9 + 9)};
vector<array<int64_t, 2>> P(N), P_(N);

int64_t power(int64_t b, int64_t p, int j) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD[j]; }
        b = b * b % MOD[j];
        p /= 2;
    }
    return res;
}

int solve(vector<int> a, vector<int> b) {
    int n = (int)a.size();
    array<int64_t, 2> X = {0, 0}, Y = {0, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            X[j] = (X[j] + P[i][j] * a[i] % MOD[j]) % MOD[j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 2; ++j) {
            Y[j] = (Y[j] + P[n - i - 1][j] * b[i] % MOD[j]) % MOD[j];
        }
    }
    int not_valid_cnt = 0;
    vector<bool> not_valid(n, false);
    for (int i = 0; i < n; ++i) {
        if ((n & 1) && (i == n / 2)) { continue; }
        if (i < n / 2 && a[i] >= b[i]) {
            not_valid[i] = true;
            not_valid_cnt++;
        }
        if (i >= n / 2 && a[i] <= b[i]) {
            not_valid[i] = true;
            not_valid_cnt++;
        }
    }
    function<void(int, int)> validate = [&](int j, int t) {
        if (t == 0) {
            if (a[j] < b[j]) {
                if (not_valid[j] == true) { not_valid_cnt--; }
                not_valid[j] = false;
            } else {
                if (not_valid[j] == false) { not_valid_cnt++; }
                not_valid[j] = true;
            }
        } else if (t == 1) {
            if (not_valid[j] == true) { not_valid_cnt--; }
            not_valid[j] = false;
        } else {
            if (a[j] > b[j]) {
                if (not_valid[j] == true) { not_valid_cnt--; }
                not_valid[j] = false;
            } else {
                if (not_valid[j] == false) { not_valid_cnt++; }
                not_valid[j] = true;
            }
        }
    };
    if (X == Y && not_valid_cnt == 0) { return 0; }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            X[j] = (X[j] - a[i] + MOD[j]) % MOD[j];
            X[j] = X[j] * P_[1][j] % MOD[j];
            X[j] = (X[j] + P[n - 1][j] * b[i] % MOD[j]) % MOD[j];
            Y[j] = (Y[j] - P[n - 1][j] * b[i] % MOD[j] + MOD[j]) % MOD[j];
            Y[j] = (P[1][j] * Y[j] % MOD[j] + a[i]) % MOD[j];
        }
        if (n & 1) {
            if (n / 2 + (i + 1) < n) {
                validate(n / 2 + (i + 1), 1);
            } else {
                validate((n / 2) + (i + 1) - n, 1);
            }
            if (n / 2 + i < n) {
                validate(n / 2 + i, 0);
            } else {
                validate((n / 2) + i - n, 2);
            }
        } else {
            if (n / 2 + i < n) {
                validate(n / 2 + i, 0);
            } else {
                validate((n / 2) + i - n, 2);
            }
        }
        validate(i, 0);
        if (X == Y && not_valid_cnt == 0) { return i + 1; }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    P[0] = {1, 1}, P_[0] = {1, 1};
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            P[i][j] = P[i - 1][j] * B[j] % MOD[j];
            P_[i][j] = power(P[i][j], MOD[j] - 2, j);
        }
    }
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int ans1 = solve(a, b);
        int ans2 = solve(b, a);
        int ans = ans1;
        if (ans2 != -1) {
            ans = (ans == -1 ? ans2 + n : min(ans1, ans2 + n));
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
