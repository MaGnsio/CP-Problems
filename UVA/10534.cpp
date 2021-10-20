/**
 *    author:  MaGnsi0
 *    created: 07/09/2021 23:13:22
**/
#include <bits/stdc++.h>
using namespace std;

//O(n log k) Greedy + D&C Algorithm
void LIS(vector<int>& A, vector<int>& memo) {
    int n = A.size(), k = 0;
    vector<int> L(n, 0);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        if (pos == k) {
            k++;
        }
        memo[i] = pos + 1;
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<int> dp1(n), dp2(n);
        LIS(v, dp1);
        reverse(v.begin(), v.end());
        LIS(v, dp2);
        reverse(dp2.begin(), dp2.end());
        int res = 1;
        for (int i = 0; i < n; ++i) {
            res = max(res, 2 * min(dp1[i], dp2[i]) - 1);
        }
        cout << res << "\n";
    }
}
