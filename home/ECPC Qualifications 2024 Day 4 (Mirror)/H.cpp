/**
 *    author:  MaGnsi0
 *    created: 25.07.2024 15:55:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (k > n) {
            cout << -1 << "\n";
            continue;
        }
        sort(a.begin(), a.end());
        vector<int> tops;
        while ((int)tops.size() < k) {
            tops.push_back(a.back());
            a.pop_back();
        }
        assert(tops.size() == k);
        if ((int)a.size() < k + 1) {
            cout << -1 << "\n";
            continue;
        }
        sort(tops.begin(), tops.end());
        vector<int> ans;
        ans.push_back(a[0]);
        for (int i = 0; i < k; ++i) {
            ans.push_back(tops[i]);
            ans.push_back(a[i + 1]);
        }
        for (int i = k + 1; i < (int)a.size(); ++i) {
            ans.push_back(a[i]);
        }
        for (int i = 1; i + 1 < n; ++i) {
            k -= (ans[i - 1] < ans[i] && ans[i] > ans[i + 1]);
        }
        if (k > 0) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
