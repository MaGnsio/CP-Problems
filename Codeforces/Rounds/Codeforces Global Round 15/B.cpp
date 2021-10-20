/**
 *    author:  MaGnsi0
 *    created: 27/07/2021 03:50:00
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(5));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> v[i][j];
            }
        }
        auto comp = [=](vector<int> a, vector<int> b) {
            int cnt = 0;
            for (int i = 0; i < 5; ++i) {
                cnt += (a[i] <= b[i]);
            }
            return (cnt >= 3);
        };
        int cur = 0;
        for (int i = 1; i < n; ++i) {
            cur = (comp(v[cur], v[i]) ? cur : i);
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            ok &= comp(v[cur], v[i]);
        }
        cout << (ok ? cur + 1 : -1) << "\n";
    }
}
