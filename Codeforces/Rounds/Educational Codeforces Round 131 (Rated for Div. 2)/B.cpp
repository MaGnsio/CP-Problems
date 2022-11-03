/**
 *    author:  MaGnsi0
 *    created: 08.07.2022 22:21:46
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
        vector<int> ans;
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            s.insert(i);
        }
        while (!s.empty()) {
            ans.push_back(*s.begin());
            s.erase(s.begin());
            while (s.count(2 * ans.back())) {
                ans.push_back(2 * ans.back());
                s.erase(ans.back());
            }
        }
        cout << 2 << "\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
