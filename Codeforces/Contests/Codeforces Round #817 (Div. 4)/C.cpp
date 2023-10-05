/**
 *    author:  MaGnsi0
 *    created: 30.08.2022 16:34:13
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
        vector<set<string>> a(3);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                string s;
                cin >> s;
                a[i].insert(s);
            }
        }
        vector<int> ans(3, 0);
        for (int i = 0; i < 3; ++i) {
            for (auto& x : a[i]) {
                int cnt = a[0].count(x) + a[1].count(x) + a[2].count(x);
                ans[i] += (cnt == 1 ? 3 : (cnt == 2 ? 1 : 0)); 
            }
        }
        for (int i = 0; i < 3; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
