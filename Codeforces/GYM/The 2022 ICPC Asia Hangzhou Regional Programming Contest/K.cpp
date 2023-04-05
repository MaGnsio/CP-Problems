/**
 *    author:  MaGnsi0
 *    created: 21.01.2023 04:24:18
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
    int cnt = 0;
    map<char, int> next;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<node> T(1, node());
    vector<vector<int64_t>> F(27, vector<int64_t>(27));
    function<void(string)> insert = [&](string s) {
        int root = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (T[root].next[s[i]] == 0) {
                T[root].next[s[i]] = (int)T.size();
                T.push_back(node());
            }
            for (auto& [c, j] : T[root].next) {
                if (c == s[i]) { continue; }
                F[s[i] - 'a' + 1][c - 'a' + 1] += T[j].cnt;
            }
            root = T[root].next[s[i]];
            T[root].cnt++;
        }
    };
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        s.push_back(char('a' - 1));
        insert(s);
    }
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        s = char('a' - 1) + s;
        int64_t ans = 0;
        for (int j = 0; j < 27; ++j) {
            for (int k = j + 1; k < 27; ++k) {
                ans += F[s[j] - 'a' + 1][s[k] - 'a' + 1];
            }
        }
        cout << ans << "\n";
    }
}
