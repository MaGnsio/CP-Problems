/**
 *    author:  MaGnsi0
 *    created: 12.09.2022 16:33:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        if (s[0] <= s[n - 1]) {
            set<char> _s(s.begin(), s.end());
            string path = "";
            for (auto& x : _s) {
                if (x >= s[0]) {
                    path += x;
                }
                if (x == s[n - 1]) {
                    break;
                }
            }
            vector<vector<int>> adj(26);
            for (int i = 0; i < n; ++i) {
                adj[s[i] - 'a'].push_back(i + 1);
            }
            vector<int> ans;
            for (int i = 0; i < (int)path.size(); ++i) {
                ans.insert(ans.end(), adj[path[i] - 'a'].begin(), adj[path[i] - 'a'].end());
            }
            int res = 0;
            for (int i = 1; i < (int)path.size(); ++i) {
                res += path[i] - path[i - 1];
            }
            cout << res << " " << (int)ans.size() << "\n";
            for (int i = 0; i < (int)ans.size(); ++i) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        } else {
            set<char> _s(s.begin(), s.end());
            string path = "";
            for (auto& x : _s) {
                if (x >= s[n - 1]) {
                    path += x;
                }
                if (x == s[0]) {
                    break;
                }
            }
            reverse(path.begin(), path.end());
            vector<vector<int>> adj(26);
            for (int i = 0; i < n; ++i) {
                adj[s[i] - 'a'].push_back(i + 1);
            }
            vector<int> ans;
            for (int i = 0; i < (int)path.size(); ++i) {
                ans.insert(ans.end(), adj[path[i] - 'a'].begin(), adj[path[i] - 'a'].end());
            }
            int res = 0;
            for (int i = 1; i < (int)path.size(); ++i) {
                res += path[i - 1] - path[i];
            }
            cout << res << " " << (int)ans.size() << "\n";
            for (int i = 0; i < (int)ans.size(); ++i) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
}
