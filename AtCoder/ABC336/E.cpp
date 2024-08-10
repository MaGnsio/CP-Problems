/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 15:27:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int d; cin >> d;
    vector<int64_t> X(n), Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int lx = X[0] - d, rx = X[n - 1] + d;
    int ly = Y[0] - d, ry = Y[n - 1] + d;
    for (int i = 1; i < n; ++i) {
        X[i] += X[i - 1];
        Y[i] += Y[i - 1];
    }
    map<int64_t, int64_t> countX, countY;
    for (int i = lx, j = 0; i <= rx; ++i) {
        while (j < n && X[j] - (j ? X[j - 1] : 0) < i) { j++; }
        int64_t val = 1LL * j * i - 1LL * (n - j) * i + X[n - 1] - 2 * (j ? X[j - 1] : 0);
        countX[val]++;
    }
    int64_t ans = 0, sum = 0;
    for (auto& [_, c] : countX) {
        c += sum; sum = c;
    }
    for (int i = ly, j = 0; i <= ry; ++i) {
        while (j < n && Y[j] - (j ? Y[j - 1] : 0) < i) { j++; }
        int64_t val = 1LL * j * i - 1LL * (n - j) * i + Y[n - 1] - 2 * (j ? Y[j - 1] : 0);
        auto it = countX.upper_bound(d - val);
        if (it == countX.begin()) { continue; }
        it--;
        ans += it -> second;
    }
    cout << ans;
}
