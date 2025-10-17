/**
 *    author:  MaGnsi0
 *    created: 17.10.2025 17:42:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ans.push_back(i + 1);
            }
        }
        cout << (int)ans.size() << "\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
