/**
 *    author:  MaGnsi0
 *    created: 27/07/2021 03:59:10
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
        vector<pair<int, int>> chords;
        vector<bool> used(2 * n + 1, false);
        for (int i = 0; i < k; ++i) {
            int a, b;
            cin >> a >> b;
            if (a > b) {
                swap(a, b);
            }
            chords.push_back({a, b});
            used[a] = used[b] = true;
        }
        vector<int> not_used;
        for (int i = 1; i <= 2 * n; ++i) {
            if (!used[i]) {
                not_used.push_back(i);
            }
        }
        int m = not_used.size();
        for (int i = 0; i < m / 2; ++i) {
            chords.push_back({not_used[i], not_used[m / 2 + i]});
        }
        int res = 0;
        auto intersection = [](pair<int, int> a, pair<int, int> b) {
            if (a > b) {
                swap(a, b);
            }
            return (a.first < b.first && a.second > b.first && a.second < b.second ? 1 : 0);
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res += intersection(chords[i], chords[j]);
            }
        }
        cout << res << "\n";
    }
}
