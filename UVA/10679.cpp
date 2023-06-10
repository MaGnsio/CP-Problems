/**
 *    author:  MaGnsi0
 *    created: 08.05.2023 19:41:06
**/
#include <bits/stdc++.h>

using namespace std;

const int K = 52;

struct vertex {
    char c;
    set<int> output;
    int p = -1, link = -1;
    int next[K], go[K];
    vertex(int p = -1, char c = '$') : p(p), c(c) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<vertex> t(1);

void insert(int j, string s) {
    int v = 0;
    for (auto& c : s) {
        int x = (isupper(c) ? (c - 'A' + 25) : (c - 'a'));
        if (t[v].next[x] == -1) {
            t[v].next[x] = (int)t.size();
            t.emplace_back(v, c);
        }
        v = t[v].next[x];
    }
    t[v].output.insert(j);
}

void build_fsa() {
    queue<int> q;
    q.push(0); t[0].link = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int c = 0; c < K; ++c) {
            if (t[v].next[c] != -1) {
                t[v].go[c] = t[v].next[c];
                t[t[v].go[c]].link = (v == 0 ? 0 : t[t[v].link].go[c]);
                q.push(t[v].go[c]);
            } else {
                assert(t[v].link != -1);
                t[v].go[c] = (v == 0 ? 0 : t[t[v].link].go[c]);
            }
        }
    }
}

set<int> found;

void go(string s) {
    int v = 0;
    for (auto& c : s) {
        int x = (isupper(c) ? (c - 'A' + 26) : (c - 'a'));
        v = t[v].go[x];
        for (auto& j : t[v].output) {
            found.insert(j);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int m;
        string s;
        cin >> s >> m;
        for (int i = 0; i < m; ++i) {
            string t;
            cin >> t;
            insert(i, t);
        }
        build_fsa();
        go(s);
        for (int i = 0; i < m; ++i) {
            cout << (found.count(i) ? "y" : "n") << "\n";
        }
        found.clear();
        t = vector<vertex>(1);
    }
}
