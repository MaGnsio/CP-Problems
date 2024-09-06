/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 00:41:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            ans.push_back(s.find('#') + 1);
        }
        reverse(ans.begin(), ans.end());
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
