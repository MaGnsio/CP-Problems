/**
 *    author:  MaGnsi0
 *    created: 09.05.2023 00:07:32
**/
#include <bits/stdc++.h>

using namespace std;

const int K = 26;

struct vertex {
    char c;
    int output = -1;
    int p = -1, link = -1, exit = -1;
    int next[K];
    vertex(int p = -1, char c = '$') : p(p), c(c) {
        fill(begin(next), end(next), -1);
    }
};

vector<vertex> t(1);

void insert(int j, string s) {
    int v = 0;
    for (auto c : s) {
        if (t[v].next[c - 'a'] == -1) {
            t[v].next[c - 'a'] = (int)t.size();
            t.emplace_back(v, c);
        }
        v = t[v].next[c - 'a'];
    }
    t[v].output = j;
}

void compute_automaton() {
    queue<int> q;
    q.push(0); t[0].link = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        t[v].exit = (t[t[v].link].output == -1 ? t[t[v].link].exit : t[v].link);
        for (int c = 0; c < K; ++c) {
            if (t[v].next[c] != -1) {
                t[t[v].next[c]].link = (v == 0 ? 0 : t[t[v].link].next[c]);
                q.push(t[v].next[c]);
            } else {
                t[v].next[c] = (v == 0 ? 0 : t[t[v].link].next[c]);
            }
        }
    }
}

vector<int> solve(int& k, string& s) {
    int n = (int)s.size(), v = 0;
    vector<int> ans(2 * n, -1);
    for (int i = 0; i < 2 * n; ++i) {
        v = t[v].next[s[i % n] - 'a'];
        if (t[v].output != -1) {
            ans[i - k + 1] = t[v].output;
        }
        if (t[v].exit != -1) {
            ans[i - k + 1] = t[t[v].exit].output;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, m;
    string s;
    cin >> n >> k;
    cin >> s >> m;
    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        insert(i, t);
    }
    compute_automaton();
    vector<int> ans = solve(k, s);
    for (int i = 0; i < k; ++i) {
        set<int> s_;
        for (int j = i, cnt = 0; cnt < n; j += k, ++cnt) {
            if (s_.count(ans[j]) || ans[j] == -1) { break; }
            s_.insert(ans[j]);
        }
        if (s_.size() == n) {
            cout << "YES\n";
            for (int j = i, cnt = 0; cnt < n; j += k, ++cnt) {
                cout << ans[j] + 1 << " ";
            }
            return 0;
        }
    }
    cout << "NO";
}
