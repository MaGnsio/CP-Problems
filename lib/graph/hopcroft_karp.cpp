/*
 * Description: Fast bipartite matching algorithm. Graph g should be a list
 * of neighbors of the left partition, and btoa should be a vector full of
 * -1's of the same size as the right partition. Returns the size of
 * the matching. btoa[i] will be the match for vertex i on the right side,
 * or -1 if it's not matched.
 * Usage: vector<int> btoa(m, -1); hopcroftKarp(g, btoa);
 * Time: O(E * sqrt(V))
 */
bool dfs(int a, int L, vector<vector<int>>& g, vector<int>& btoa, vector<int>& A, vector<int>& B) {
    if (A[a] != L) { return false; }
    A[a] = -1;
    for (auto& b : g[a]) {
        if (B[b] == L + 1) {
            B[b] = 0;
            if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B)) {
                btoa[b] = a;
                return true;
            }
        }
    }
    return false;
}

int hopcroft_karp(vector<vector<int>>& g, vector<int>& btoa) {
    int res = 0;
    vector<int> A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(A.begin(), A.end(), 0);
        fill(B.begin(), B.end(), 0);
        cur.clear();
        for (auto& a : btoa) {
            if(a != -1) { A[a] = -1; }
        }
        for (int a = 0; a < (int)g.size(); ++a) {
            if(A[a] == 0) { cur.push_back(a); }
        }
        for (int lay = 1;; ++lay) {
            bool islast = 0;
            next.clear();
            for (auto& a : cur) {
                for (auto& b : g[a]) {
                    if (btoa[b] == -1) {
                        B[b] = lay;
                        islast = 1;
                    } else if (btoa[b] != a && !B[b]) {
                        B[b] = lay;
                        next.push_back(btoa[b]);
                    }
                }
            }
            if (islast) { break; }
            if (next.empty()) { return res; }
            for (auto& a : next) { A[a] = lay; }
            cur.swap(next);
        }
        for (int a = 0; a < (int)g.size(); ++a) {
            res += dfs(a, 0, g, btoa, A, B);
        }
    }
}
