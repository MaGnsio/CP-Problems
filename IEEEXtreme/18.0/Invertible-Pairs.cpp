/**
 *    author:  MaGnsi0
 *    created: 27.10.2024 01:11:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cur_sum = 0, max_sum = 0;
        for (int i = 0; i < n; i += 2) {
            max_sum = max(max_sum, cur_sum + abs(a[i]));
            cur_sum += max(+1 * (a[i] + a[i + 1]), -1 * (a[i] + a[i + 1]));
            cur_sum = max(cur_sum, 0);
            cur_sum = max(cur_sum, abs(a[i + 1]));
            max_sum = max(max_sum, cur_sum);
        }
        cout << max_sum << "\n";
    }
}
