/**
 *    author:  MaGnsi0
 *    created: 25.12.2022 06:12:35
**/

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = (int)price.size();
        sort(price.begin(), price.end());
        int l = 0, r = 1e9, ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int last_taken = 0, taken = 1;
            for (int i = 1; i < n; ++i) {
                if (taken == k) {
                    break;
                }
                if (price[i] - price[last_taken] >= m) {
                    last_taken = i;
                    taken++;
                }
            }
            if (taken == k) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
