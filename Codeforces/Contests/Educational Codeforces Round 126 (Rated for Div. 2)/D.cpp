/**
 *    author:  MaGnsi0
 *    created: 09.04.2022 16:27:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int64_t> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    vector<int64_t> A(N, 0), C(N + 1, 0);
    for (int i = N - 1; i >= 0; --i) {
        int64_t D = B[i] - A[i];
        if (D > 0) {
            int64_t k = (i < K ? i + 1 : K);
            C[i] = (D + k - 1) / k;
            A[i] += C[i] * k;
        }
        C[i] += C[i + 1];
        if (i) {
            int j = min(N, i + K);
            A[i - 1] = A[i] - (C[i] - C[j]);
        }
    }
    cout << C[0];
}
