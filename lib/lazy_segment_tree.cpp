struct segment_tree {
    private:
        int n;
        vector<int> tree, lazy;
    public:
        segment_tree(int n) {
            this -> n = n;
            tree.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }
        void update(int l, int r, int v) {
            update(1, 0, n - 1, l, r, v);
        }
        int query (int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    private:
        void update_lazy(int node, int l, int r, int v) {
            lazy[node] += v;
            tree[node] += v * (r - l + 1);
        }
        void push_down(int node, int l, int r) {
            int m = (l + r) / 2;
            update_lazy(2 * node, l, m, lazy[node]);
            update_lazy(2 * node + 1, m + 1, r, lazy[node]);
            lazy[node] = 0;
        }
        void update(int node, int l, int r, int ul, int ur, int v) {
            if (r < ul || l > ur) {
                return;
            }
            if (ul <= l && r <= ur) {
                update_lazy(node, l, r, v);
                return;
            }
            push_down(node, l, r);
            int m = (l + r) / 2;
            update(2 * node, l, m, ul, ur, v);
            update(2 * node + 1, m + 1, r, ul, ur, v);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
        int query(int node, int l, int r, int ul, int ur) {
            if (r < ul || l > ur) {
                return 0;
            }
            push_down(node, l, r);
            if (ul <= l && r <= ur) {
                tree[node] = tree[2 * node] + tree[2 * node + 1];
                return tree[node];
            }
            int m = (l + r) / 2;
            return (query(2 * node, l, m, ul, ur) + query(2 * node + 1, m + 1, r, ul, ur));
        }
};
