/**
 *    author:  MaGnsi0
 *    created: 03.07.2022 23:41:52
**/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        int m = (int)nums2.size();
        function<int(int)> get_element = [&](int k) {
            if (k <= n && (m == 0 || nums1[k - 1] <= nums2[0])) {
                return nums1[k - 1];
            }
            if (k <= m && (n == 0 || nums2[k - 1] <= nums1[0])) {
                return nums2[k - 1];
            }
            int L = max(1, k - m), R = min(n, k - 1);
            while (L <= R) {
                int M = (L + R) / 2;
                if (nums1[M - 1]  > nums2[k - M - 1]) {
                    if (k - M - 1 == m - 1 || nums2[k - M] >= nums1[M - 1]) {
                        return nums1[M - 1];
                    } else {
                        R = M - 1;
                    }
                } else if (nums2[k - M - 1] > nums1[M - 1]) {
                    if (M - 1 == n - 1 || nums1[M] >= nums2[k - M - 1]) {
                        return nums2[k - M - 1];
                    } else {
                        L = M + 1;
                    }
                } else {
                    return nums1[M - 1];
                }
            }
            return 0;
        };
        double ans = get_element((n + m + 1) / 2);
        if ((n + m) % 2 == 0) {
            ans += get_element((n + m) / 2 + 1);
            ans /= 2.0;
        }
        return ans;
    }
};
