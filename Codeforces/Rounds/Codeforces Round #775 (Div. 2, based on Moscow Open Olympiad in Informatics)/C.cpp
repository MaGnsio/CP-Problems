/**
 *    author:  MaGnsi0
 *    created: 06.03.2022 11:49:23
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long calc(vector<int> a) {
    if (a.empty()) {
        return 0LL;
    }
    long long res = 0, p = a[0];
    for (int i = 1; i < (int)a.size(); ++i) {
        res += (1LL * i * a[i] - p);
        p += 1LL * a[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> X(N), Y(N);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            X[a[i][j]].push_back(i);
            Y[a[i][j]].push_back(j);
        }
    }
    for (int i = 0; i < N; ++i) {
        sort(X[i].begin(), X[i].end());
        sort(Y[i].begin(), Y[i].end());
    }
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += calc(X[i]);
        ans += calc(Y[i]);
    }
    cout << ans;
}
