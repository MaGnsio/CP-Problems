/**
 *    author:  MaGnsi0
 *    created: 25.12.2022 06:12:11
**/

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = (int)s.size();
        vector<vector<int>> pre(3, vector<int>(n));
        vector<vector<int>> suf(3, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            pre[s[i] - 'a'][i]++;
            suf[s[i] - 'a'][i]++;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                pre[j][i] += pre[j][i - 1];
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < 3; ++j) {
                suf[j][i] += suf[j][i + 1];
            }
        }
        if (suf[0][0] < k || suf[1][0] < k || suf[2][0] < k) {
            return -1;
        }
        if (k == 0) {
            return 0;
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n - 1;
            bool ok = (pre[0][i] >= k);
            ok &= (pre[1][i] >= k);
            ok &= (pre[2][i] >= k);
            if (ok) {
                ans = min(ans, i + 1);
            }
            while (l <= r) {
                int m = (l + r) / 2;
                bool ok = (pre[0][i] + suf[0][m] >= k);
                ok &= (pre[1][i] + suf[1][m] >= k);
                ok &= (pre[2][i] + suf[2][m] >= k);
                if (ok) {
                    ans = min(ans, i + 1 + n - m);
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int l = 0, r = i - 1;
            bool ok = (suf[0][i] >= k);
            ok &= (suf[1][i] >= k);
            ok &= (suf[2][i] >= k);
            if (ok) {
                ans = min(ans, n - i);
            }
            while (l <= r) {
                int m = (l + r) / 2;
                bool ok = (pre[0][m] + suf[0][i] >= k);
                ok &= (pre[1][m] + suf[1][i] >= k);
                ok &= (pre[2][m] + suf[2][i] >= k);
                if (ok) {
                    ans = min(ans, m + 1 + n - i);
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return ans;
    }
};
