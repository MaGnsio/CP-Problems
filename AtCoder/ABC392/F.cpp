/**
 *    author:  MaGnsi0
 *    created: 08.02.2025 14:40:20
**/
#include <bits/stdc++.h>

using namespace std;

random_device random_seed;
mt19937 rng(random_seed());

class implicit_treap {
    public:
        struct node {
            int sz, priority, lazy, rev, sum;
            int val, key;
            node *l, *r, *par;
            node() {
                lazy = 0; rev = 0; val = 0; sz = 0; key = 0; priority = 0;
                l = NULL; r = NULL; par = NULL;
            }
            node(int _val) {
                val = _val; sum = _val; rev = 0; lazy = 0; key = 0; sz = 1; priority = rng();
                l = nullptr; r = nullptr; par = nullptr;
            }
        };
        typedef node* pnode;
    private:
        pnode root;
        map<int, pnode> position;
        int size(pnode p) { return p ? p -> sz : 0; }
        void update_size(pnode &p) { if (p) { p -> sz = size(p -> l) + size(p -> r) + 1; } }
        void update_parent(pnode &p) {
            if (!p) { return; }
            if (p -> l) { p -> l -> par = p; }
            if (p -> r) { p -> r -> par = p; }
        }
        void push(pnode &p) {
            if (!p) { return; }        
            p -> sum += size(p) * p -> lazy;
            p -> val += p -> lazy;
            if (p -> rev) { swap(p -> l, p -> r); }
            if (p -> l) { p -> l -> lazy += p -> lazy; p -> l -> rev ^= p -> rev; }
            if (p -> r) { p -> r -> lazy += p -> lazy; p -> r -> rev ^= p -> rev; }
            p -> lazy = 0; p -> rev = 0;
        }
        void reset(pnode &t) { if (t) { t -> sum = t -> val; } }
        void combine(pnode &t, pnode l, pnode r) {
            if (!l) { t = r; return; }
            if (!r) { t = l; return; }
            t -> sum = l -> sum + r -> sum;
        }
        void operation(pnode &t) {
            if (!t) { return; }
            reset(t);
            push(t -> l);
            push(t -> r);
            combine(t, t -> l, t);
            combine(t, t, t -> r);
        }
        void split(pnode t, pnode &l, pnode &r, int k, int add = 0) {
            if (t == NULL) { l = NULL; r = NULL; return; }
            push(t);
            int idx = add + size(t -> l);
            if (idx <= k) { 
                split(t -> r, t -> r, r, k, idx + 1), l = t;
            } else {
                split(t -> l, l, t -> l, k, add), r = t;
            }
            update_parent(t);
            update_size(t);
            operation(t);
        }
        void merge(pnode &t, pnode l, pnode r) {
            push(l);
            push(r);
            if (!l) { t = r; return; }
            if (!r) { t = l; return; }
            if (l -> priority > r -> priority) {
                merge(l -> r, l -> r, r), t = l;
            } else {
                merge(r -> l, l, r -> l), t = r;
            }
            update_parent(t);
            update_size(t);
            operation(t);
        }
        int get_pos(pnode curr, pnode son = nullptr) {
            if (!son) {
                if (!curr -> par) return size(curr -> l);
                else return size(curr -> l) + get_pos(curr -> par, curr);
            }
            if (!curr -> par) {
                if (son == curr -> l) return 0;
                else return size(curr -> l) + 1;
            }
            if (curr -> l == son) return get_pos(curr -> par, curr);
            else return get_pos(curr -> par, curr) + size(curr -> l) + 1;
        }
    public:    
        void clear() {
            root = NULL;
            position.clear();
        }
        implicit_treap() { clear(); }
        void insert(int pos, int key, int val) {
            if (!root) {
                pnode to_add = new node(val);
                to_add -> key = key;
                root = to_add;
                position[key] = root;
                return;
            }
            pnode l, r, mid;
            mid = new node(val);
            position[key] = mid;
            mid -> key = key;
            split(root, l, r, pos - 1);
            merge(l, l, mid);
            merge(root, l, r);
        }
        int query_sum(int qL, int qR) {
            pnode l, r, mid;
            split(root, l, r, qL - 1);
            split(r, mid, r, qR - qL);
            int answer = mid -> sum;
            merge(r, mid, r);
            merge(root, l, r);
            return answer;
        }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    implicit_treap t;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x; x--;
        t.insert(x, i, i);
    }
    for (int i = 0; i < n; ++i) {
        cout << t.query_sum(i, i) << " ";
    }
}
