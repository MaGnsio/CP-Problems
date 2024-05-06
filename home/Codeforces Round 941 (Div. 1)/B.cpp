/**
 *    author:  MaGnsi0
 *    created: 27.04.2024 17:57:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int64_t P2 = 0;
        vector<int64_t> ans;
        if (k == 1) {
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(3);
            ans.push_back(4);
            P2 = 3;
        }
        while ((1LL << P2) < n) {
            int64_t low = (1LL << P2);
            int64_t high = 2LL * low - 1;
            if (low <= k && k <= high) {
                if (k == low) {
                    int64_t x = low + 1;
                    ans.push_back(low + 1);
                    ans.push_back(low + 1);
                    int64_t have = x * x * x;
                    while (have <= n) {
                        ans.push_back(have);
                        have *= x;
                    }
                } else {
                    int64_t x = low - 1;
                    ans.push_back(low - 1);
                    ans.push_back(low - 1);
                    int64_t have = 4 * x;
                    while (have <= n) {
                        ans.push_back(have);
                        have *= 2;
                    }
                }
            } else {
                ans.push_back(low);
            }
            P2++;
        }
        int m = (int)ans.size();
        assert(m <= 25);
        cout << m << "\n";
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
