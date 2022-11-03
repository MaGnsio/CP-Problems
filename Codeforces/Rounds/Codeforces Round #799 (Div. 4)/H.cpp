/**
 *    author:  MaGnsi0
 *    created: 14.06.2022 20:00:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]].push_back(i);
        }
        int best = 0, ans, L, R;
        for (auto& [x, b] : mp) {
            int sum = 1, l = b[0], r = b[0];
            for (int i = 1, last_l = b[0], cur_sum = 1; i < (int)b.size(); ++i) {
                if (cur_sum + 1 - (b[i] - b[i - 1] - 1) <= 0) {
                    last_l = b[i];
                    cur_sum = 1;
                } else {
                    cur_sum += 1 - (b[i] - b[i - 1] - 1);
                }
                if (cur_sum > sum) {
                    sum = cur_sum;
                    l = last_l;
                    r = b[i];
                }
            }
            if (sum > best) {
                best = sum;
                ans = x;
                L = l;
                R = r;
            }
        }
        cout << ans << " " << L + 1 << " " << R + 1 << "\n";
    }
}
