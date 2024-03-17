/**
 *    author:  MaGnsi0
 *    created: 05.01.2024 21:25:48
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> mins(n, OO), maxs(n, -OO), good(n, 0);
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            good[i] |= mins[i] < x;
            mins[i] = min(mins[i], x);
            maxs[i] = max(maxs[i], x);
        }
    }
    int goods = 0;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            maxs[i] = -1;
            goods++;
        }
    }
    int64_t ans = 0;
    sort(maxs.rbegin(), maxs.rend());
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            ans += n;
        } else {
            int low = 0, high = n - 1, add = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (maxs[mid] > mins[i]) {
                    add = mid + 1;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans += add + goods;
        }
    }
    cout << ans;
}
