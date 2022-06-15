/**
 *    author:  MaGnsi0
 *    created: 30.04.2022 10:59:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, sum = 0;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += (int)a[i].size();
        }
        vector<string> b(26, "");
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (count(a[i].begin(), a[i].end(), a[i][0]) == (int)a[i].size()) {
                b[a[i][0] - 'A'] += a[i];
                visited[i] = true;
            }
        }
        vector<int> next(26, -1);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (next[a[i][0] - 'A'] != -1) {
                    break;
                }
                b[a[i][0] - 'A'] += a[i];
                visited[i] = true;
                next[a[i][0] - 'A'] = a[i].back() - 'A';
            }
        }
        cout << "Case #" << t << ": ";
        if (count(visited.begin(), visited.end(), true) != n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        function<bool(string)> ok = [&](string s) {
            vector<bool> found(26, false);
            found[s[0] - 'A'] = true;
            for (int i = 1; i < (int)s.size(); ++i) {
                if (s[i] == s[i - 1]) {
                    continue;
                } else if (found[s[i] - 'A']) {
                    return false;
                } else {
                    found[s[i] - 'A'] = true;
                }
            }
            return true;
        };
        set<int> roots;
        for (int i = 0; i < 26; ++i) {
            roots.insert(i);
        }
        for (int i = 0; i < 26; ++i) {
            roots.erase(next[i]);
        }
        string ans = "";
        vector<bool> found(26, false);
        for (auto& root : roots) {
            int x = root;
            ans += b[x];
            found[x] = true;
            while (next[x] != -1 && !found[next[x]]) {
                x = next[x];
                ans += b[x];
                found[x] = true;
            }
        }
        cout << ((int)ans.size() == sum && ok(ans) ? ans : "IMPOSSIBLE") << "\n";
    }
}
