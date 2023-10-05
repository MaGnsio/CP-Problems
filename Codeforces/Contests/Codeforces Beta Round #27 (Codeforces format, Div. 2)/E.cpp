/**
 *    author:  MaGnsi0
 *    created: 25.12.2021 21:32:14
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3, M = 10;
int maxP[M];
const unsigned long long P[M] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
const unsigned long long OO = LLONG_MAX;
unsigned long long dp[N][M + 1];

template <typename T>
T power(T b, T p) {
    T res = 1LL;
    while (p) {
        if (p & 1) {
            res *= b;
        }
        b *= b;
        p /= 2;
    }
    return res;
}

void run() {
    for (int i = 0; i < M; ++i) {
        unsigned long long x = 1; 
        while (x <= OO / P[i]) {
            x *= P[i];
            maxP[i]++;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= M; ++j) {
            dp[i][j] = OO;
        }
    }
    dp[1][0] = 1;
    for (int j = 1; j <= M; ++j) {
        for (int i = 1; i < N; ++i) {
            for (int k = 1; k <= maxP[j - 1] + 1; ++k) {
                if (i % k) {
                    continue;
                }
                if (dp[i / k][j - 1] == OO) {
                    continue;
                }
                unsigned long long p = power<unsigned long long>(P[j - 1], k - 1);
                if (p >= OO / dp[i / k][j - 1]) {
                    continue;
                }
                dp[i][j] = min(dp[i][j], p * dp[i / k][j - 1]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    run();
    int n;
    cin >> n;
    cout << dp[n][M];
}
