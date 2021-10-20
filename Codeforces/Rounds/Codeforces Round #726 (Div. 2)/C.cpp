/**
 *    author:  MaGnsi0
 *    created: 18/06/2021 16:27:05
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n), ans;
        for (auto& x : v) {
            cin >> x;
        }
        sort(v.begin(), v.end());
        int x, mini = INT_MAX;
        for (int i = 0; i < n - 1; ++i) {
            if (v[i + 1] - v[i] <= mini) {
                x = i;
                mini = v[i + 1] - v[i];
            }
        }
        for (int i = x; i < n; ++i) {
            if (i == x + 1) {
                continue;
            }
            ans.push_back(v[i]);
        }
        for (int i = 0; i <= x + 1; ++i) {
            if (i == x) {
                continue;
            }
            ans.push_back(v[i]);
        }
        for (auto& x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
