/**
 *    author:  MaGnsi0
 *    created: 28.12.2023 18:19:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        string now = "", t = "";
        set<char> C = {'b', 'c', 'd'};
        vector<string> ans;
        for (int i = n - 1; i >= 0; --i) {
            now += s[i];
            t += (C.count(s[i]) ? 'C' : 'V');
            if (t == "VC") {
                reverse(now.begin(), now.end());
                ans.push_back(now);
                t = now = "";
            } else if (t == "CVC") {
                reverse(now.begin(), now.end());
                ans.push_back(now);
                t = now = "";
            }
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < (int)ans.size(); ++i) {
            if (i) { cout << "."; }
            cout << ans[i];
        }
        cout << "\n";
    }
}
