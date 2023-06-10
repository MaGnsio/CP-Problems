const int K = 26;

struct vertex {
    char c;
    bool output = false;
    int p = -1, link = -1;
    int next[K], go[K];
    vertex(int p = -1, char c = '$') : p(p), c(c) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
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
    t[v].output = true;
}

void compute_automaton() {
    queue<int> q;
    q.push(0); t[0].link = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int c = 0; c < K; ++c) {
            if (t[v].next[c] != -1) {
                t[v].go[c] = t[v].next[c];
                t[t[v].go[c]].link = (v == 0 ? 0 : t[t[v].link].go[c]);
                q.push(t[v].go[c]);
            } else {
                t[v].go[c] = (v == 0 ? 0 : t[t[v].link].go[c]);
            }
        }
    }
}
