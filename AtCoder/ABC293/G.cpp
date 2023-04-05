/**
 *    author:  MaGnsi0
 *    created: 13.03.2023 23:52:35
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int B = sqrt(N) + 1;
    vector<int> L(Q), R(Q), I(Q);
    for (int q = 0; q < Q; ++q) {
        cin >> L[q] >> R[q];
        L[q]--, R[q]--, I[q] = q;
    }
    sort(I.begin(), I.end(), [&](int i, int j) {
            return make_pair(L[i] / B, R[i]) < make_pair(L[j] / B, R[j]);
        });
    int64_t res = 0;
    vector<int64_t> F(M, 0), ans(Q, 0);
    function<void(int)> add = [&](int j) {
        if (j < 0 || j >= N) { return; }
        int x = A[j];
        res -= F[x] * (F[x] - 1) * (F[x] - 2) / 6;
        F[x]++;
        res += F[x] * (F[x] - 1) * (F[x] - 2) / 6;
    };
    function<void(int)> remove = [&](int j) {
        if (j < 0 || j >= N) { return; }
        int x = A[j];
        res -= F[x] * (F[x] - 1) * (F[x] - 2) / 6;
        F[x]--;
        res += F[x] * (F[x] - 1) * (F[x] - 2) / 6;
    };
    int l = -1, r = -1;
    for (int q = 0; q < Q; ++q) {
        int j = I[q];
        while (l > L[j]) {
            l--;
            add(l);
        }
        while (r < R[j]) {
            r++;
            add(r);
        }
        while (l < L[j]) {
            remove(l);
            l++;
        }
        while (r > R[j]) {
            remove(r);
            r--;
        }
        ans[j] = res;
    }
    for (int q = 0; q < Q; ++q) {
        cout << ans[q] << "\n";
    }
}
