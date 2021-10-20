/**
 *    author:  MaGnsi0
 *    created: 08/09/2021 00:47:44
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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> rpos(n), rneg(n);
        for (int i = n - 1; i >= 0; --i) {
            cin >> rpos[i];
            rneg[i] = -rpos[i];
        }
        vector<int> dp1(n, 1), dp2(n, 1);
        LIS(rneg, dp1);
        LIS(rpos, dp2);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dp1[i] + dp2[i] - 1);
        }
        cout << res << "\n";
    }
}
