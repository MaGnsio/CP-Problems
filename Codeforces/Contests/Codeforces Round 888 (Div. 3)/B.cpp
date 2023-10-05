/**
 *    author:  MaGnsi0
 *    created: 25.07.2023 17:42:31
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
        vector<vector<int>> b(2);
        for (int i = 0; i < n; ++i) {
            b[a[i] % 2].push_back(i);
        }
        sort(a.begin(), a.end());
        vector<int> ans(n);
        for (int i = 0, j = 0, k = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                ans[b[0][j++]] = a[i];
            } else {
                ans[b[1][k++]] = a[i];
            }
        }
        cout << (is_sorted(ans.begin(), ans.end()) ? "YES" : "NO") << "\n";
    }
}
