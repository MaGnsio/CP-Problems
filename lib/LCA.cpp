struct LCA {
    int n, m;
    vector<int> depth, first, euler;
    vector<vector<int>> mat;
    void dfs(const vector<vector<int>>& tree, int cur_depth, int v, int par) {
        depth[v] = cur_depth;
        first[v] = (int)euler.size();
        euler.push_back(v);
        for (auto& u : tree[v]) {
            if (u != par) {
                dfs(tree, cur_depth + 1, u, v);
                euler.push_back(v);
            }
        }
    }
    LCA(const vector<vector<int>>& tree, const int root) {
        n = (int)tree.size();
        depth = first = vector<int>(n);
        euler.reserve(2 * n);
        dfs(tree, 0, root, -1);
        m = (int)euler.size();
        int max_log = 32 - __builtin_clz(m);
        mat.resize(max_log);
        mat[0] = euler;
        for (int j = 1; j < max_log; ++j) {
            mat[j].resize(m - (1 << j) + 1);
            for (int i = 0; i <= m - (1 << j); ++i) {
                int u = mat[j - 1][i];
                int v = mat[j - 1][i + (1 << (j - 1))];
                mat[j][i] = (depth[u] <= depth[v] ? u : v);
            }
        }
    }
    int get(int u, int v) {
        int from = first[u];
        int to = first[v];
        if (from > to) {
            swap(from, to);
        }
        assert(0 <= from && from <= to && to <= m - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        int a = mat[lg][from];
        int b = mat[lg][to - (1 << lg) + 1];
        return (depth[a] <= depth[b] ? a : b);
    }
};
