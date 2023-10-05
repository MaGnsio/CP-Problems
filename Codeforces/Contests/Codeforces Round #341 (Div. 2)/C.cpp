/**
 *    author:  MaGnsi0
 *    created: 20.06.2022 10:44:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
    }
    vector<int64_t> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        A[i] = R[i] - L[i] + 1;
        B[i] = (R[i] / p) - ((L[i] - 1) / p);
    }
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        ans += 1.0 * 2000 * ((A[i] * A[j]) - ((A[i] - B[i]) * (A[j] - B[j]))) / (A[i] * A[j]);
    }
    cout << fixed << setprecision(6) << ans;
}
