/**
 *    author:  MaGnsi0
 *    created: 10.02.2024 14:07:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j]; a[i][j]--;
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<bool> imposter(n, false);
        for (int j = 0; j < n; ++j) {
            if (mask >> j & 1) {
                imposter[j] = true;
            }
        }
        bool good = true;
        for (int j = 0; j < n; ++j) {
            if (imposter[j]) {
                for (int x : a[j]) {
                    good = good && !imposter[x];
                }
            } else {
                bool have_imposter = false;
                for (int x : a[j]) {
                    have_imposter |= imposter[x];
                }
                good = good && have_imposter;
            }
        }
        ans += good;
    }
    cout << ans;
}
