/**
 *    author:  MaGnsi0
 *    created: 30.03.2023 22:08:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N, D, K, X, P;
    cin >> N >> D >> K >> X;
    vector<int64_t> A(N); 
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cin >> P;
    for (int i = 0; i < N; ++i) {
        while (A[i] >= P && K) {
            A[i] = double(1.0 * A[i] * (100.0 - X) / 100.0);
            K--;
        }
    }
    bool ok = true;
    for (int i = 0; i < N; ++i) {
        ok &= A[i] < P;
    }
    cout << (ok ? "YES" : "NO");
}
