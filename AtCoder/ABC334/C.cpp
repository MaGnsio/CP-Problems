/**
 *    author:  MaGnsi0
 *    created: 23.12.2023 14:07:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 2);
    for (int i = 0; i < K; ++i) {
        int x; cin >> x; A[x - 1]--;
    }
    vector<int> B;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < A[i]; ++j) {
            B.push_back(i);
        }
    }
    int M = (int)B.size();
    sort(B.begin(), B.end());
    for (int i = M - 2, sign = -1; i >= 0; --i, sign *= -1) {
        B[i] = B[i + 1] + sign * B[i];
    }
    if (M % 2 == 0) {
        cout << B[0];
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < M; ++i) {
        int W = (i + 1 < M ? B[i + 1] : 0) - (B[0] - B[i]);
        ans = min(ans, W); 
    }
    cout << ans;
}
