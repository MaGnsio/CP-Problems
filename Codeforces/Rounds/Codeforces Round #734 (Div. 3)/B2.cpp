/**
 *    author:  MaGnsi0
 *    created: 23/07/2021 16:41:47
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[i] = {x, i};
        }
        sort(v.begin(), v.end());
        vector<int> cnt(n + 1, 1), f, res(n, 0);
        for (auto& [x, y] : v) {
            if (cnt[x] > k) {
                continue;
            }
            f.push_back(y);
            cnt[x]++;
        }
        int a = f.size() / k;
        for (int i = 0; i < a * k; ++i) {
            res[f[i]] = (i % k) + 1;
        }
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
