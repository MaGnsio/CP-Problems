/**
 *    author:  MaGnsi0
 *    created: 17.06.2023 15:08:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(3 * n);
    for (int i = 0; i < 3 * n; ++i) {
        cin >> a[i];
    }
    vector<int> f(n), cnt(n, 0);
    for (int i = 0; i < 3 * n; ++i) {
        if (cnt[a[i] - 1] == 1) {
            f[a[i] - 1] = i;
        }
        cnt[a[i] - 1]++;
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    sort(ans.begin(), ans.end(), [&](int i, int j) {
            return f[i - 1] < f[j - 1];
        });
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
