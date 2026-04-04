/**
 *    author:  MaGnsi0
 *    created: 04.04.2026 16:41:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        set<int> s;
        for (int i = 1; i <= 3 * n; ++i) {
            s.insert(i);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(*s.begin()); s.erase(s.begin());
            ans.push_back(*s.rbegin()); s.erase(*s.rbegin());
            ans.push_back(*s.rbegin()); s.erase(*s.rbegin());
        }
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
