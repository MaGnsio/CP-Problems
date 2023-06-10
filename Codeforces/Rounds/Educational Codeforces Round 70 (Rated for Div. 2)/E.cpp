/**
 *    author:  MaGnsi0
 *    created: 09.05.2023 18:39:22
**/
#include <bits/stdc++.h>

using namespace std;

const int K = 26;
 
struct vertex {
    char c;
    int output = 0;
    int p = -1, link = -1;
    int next[K];
    vertex(int p = -1, char c = '$') : p(p), c(c) {
        fill(begin(next), end(next), -1);
    }
};
 
vector<vertex> t(1);
 
void insert(string s) {
    int v = 0;
    for (auto c : s) {
        if (t[v].next[c - 'a'] == -1) {
            t[v].next[c - 'a'] = (int)t.size();
            t.emplace_back(v, c);
        }
        v = t[v].next[c - 'a'];
    }
    t[v].output++;
}
 
void compute_automaton() {
    queue<int> q;
    q.push(0); t[0].link = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        t[v].output += t[t[v].link].output;
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
 
vector<int64_t> solve(string& s, vector<string>& a) {
    t = vector<vertex>(1);
    for (auto& x : a) {
        insert(x);
    }
    compute_automaton();
    int n = (int)s.size(), v = 0;
    vector<int64_t> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        v = t[v].next[s[i] - 'a'];
        ans[i] = t[v].output;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    string s;
    cin >> s >> m;
    n = (int)s.size();
    vector<string> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        insert(a[i]);
    }
    vector<int64_t> b = solve(s, a);
    reverse(s.begin(), s.end());
    for (int i = 0; i < m; ++i) {
        reverse(a[i].begin(), a[i].end());
    }
    vector<int64_t> c = solve(s, a);
    reverse(c.begin(), c.end());
    int64_t ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        ans += b[i] * c[i + 1];
    }
    cout << ans;
}
