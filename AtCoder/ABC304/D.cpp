/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 15:18:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }
    int M;
    cin >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    int K;
    cin >> K;
    vector<int> B(K);
    for (int i = 0; i < K; ++i) {
        cin >> B[i];
    }
    function<int(int)> R = [&](int i) {
        int low = 0, high = K - 1, r = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (B[mid] < Y[i]) {
                r = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return r;
    };
    function<int(int)> C = [&](int i) {
        int low = 0, high = M - 1, c = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] < X[i]) {
                c = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return c;
    };
    map<pair<int, int>, int> S;
    for (int i = 0; i < N; ++i) {
        S[{R(i), C(i)}]++;
    }
    int min_s = N, max_s = 0;
    for (auto [_, x] : S) {
        min_s = min(min_s, x);
        max_s = max(max_s, x);
    }
    if (S.size() < 1LL * (K + 1) * (M + 1)) {
        min_s = 0;
    }
    cout << min_s << " " << max_s;
}
