/**
 *    author:  MaGnsi0
 *    created: 18.05.2024 18:39:19
**/
#include <bits/stdc++.h>

using namespace std;

void LIS(vector<int>& A, vector<int>& memo) {
    int n = A.size(), k = 0;
    vector<int> L(n, 0);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        if (pos == k) { k++; }
        memo[i] = pos + 1;
    }
}

void compress(vector<int>& a) {
    int n = (int)a.size();
    set<int> S(a.begin(), a.end());
    map<int, int> I;
    for (int x : S) { I[x] = (int)I.size(); }
    for (int i = 0; i < n; ++i) {
        a[i] = I[a[i]];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), dp(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        compress(a);
        LIS(a, dp);
        int m = *max_element(dp.begin(), dp.end());
        vector<int> ans;
        map<int, int> best;
        for (int i = n - 1; i >= 0; --i) {
            if (dp[i] == m) {
                ans.push_back(i + 1);
                best[dp[i]] = max(best[dp[i]], a[i]);
            } else if (best.count(dp[i] + 1) && best[dp[i] + 1] > a[i]) {
                ans.push_back(i + 1);
                best[dp[i]] = max(best[dp[i]], a[i]);
            }
        }
        sort(ans.begin(), ans.end());
        cout << (int)ans.size() << "\n";
        for (int j : ans) { cout << j << " "; }
        cout << "\n";
    }
}
