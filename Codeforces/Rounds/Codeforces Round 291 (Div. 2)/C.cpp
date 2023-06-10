/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 02:17:25
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
    bool end;
    array<int, 3> next;
    node() {
        end = false;
        next[0] = next[1] = next[2] = -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<node> a(1);
    function<void(string)> insert = [&](string s) {
        int k = (int)s.size();
        for (int i = 0, j = 0; i < k; ++i) {
            if (a[j].next[s[i] - 'a'] == -1) {
                a[j].next[s[i] - 'a'] = (int)a.size();
                a.push_back(node());
            }
            j = a[j].next[s[i] - 'a'];
            a[j].end |= i == k - 1;
        }
    };
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        insert(s);
    }
    function<bool(string&, int, int, int)> find = [&](string& s, int i, int j, int k) {
        if (i == (int)s.size()) {
            return k && a[j].end;
        }
        bool ans = false;
        if (a[j].next[s[i] - 'a'] != -1) {
            ans |= find(s, i + 1, a[j].next[s[i] - 'a'], k);
        }
        if (k == 0) {
            for (char c = 'a'; c <= 'c'; ++c) {
                if (c == s[i]) { continue; }
                if (a[j].next[c - 'a'] == -1) { continue; }
                ans |= find(s, i + 1, a[j].next[c - 'a'], 1);
            }
        }
        return ans;
    };
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        cout << (find(s, 0, 0, 0) ? "YES" : "NO") << "\n";
    }
}
