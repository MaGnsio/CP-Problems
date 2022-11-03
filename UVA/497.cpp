/**
 *    author:  MaGnsi0
 *    created: 06.09.2022 15:49:44
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void LIS(vector<T>& A, vector<int>& memo) {
    int n = A.size(), k = 0;
    vector<T> L(n, 0);
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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    cin.ignore();
    cin.ignore();
    while (T--) {
        string s;
        vector<int> a;
        while (getline(cin, s) && s != "") {
            a.push_back(stoi(s));
        }
        int n = (int)a.size();
        vector<int> dp(n);
        LIS(a, dp);
        int cur = *max_element(dp.begin(), dp.end()) + 1, last = INT_MAX;
        vector<int> ans;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] < last && dp[i] == cur - 1) {
                ans.push_back(a[i]);
                last = a[i];
                cur--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "Max hits: " << (int)ans.size() << "\n";
        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i] << "\n";
        }
        if (T) {
            cout << "\n";
        }
    }
}
