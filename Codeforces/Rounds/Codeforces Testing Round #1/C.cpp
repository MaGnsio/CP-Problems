/**
 *    author:  MaGnsi0
 *    created: 17.02.2023 15:22:13
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e14;

struct Node {
    Node *l = 0, *r = 0;
    int64_t lo, hi, mset = OO, madd = 0, val = OO;
    Node(int lo, int hi) : lo(lo), hi(hi) {}
    Node(vector<int64_t>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = min(l -> val, r -> val);
        } else {
            val = v[lo];
        }
    }
    int64_t query(int L, int R) {
        if (R <= lo || hi <= L) return OO;
        if (L <= lo && hi <= R) return val;
        push();
        return min(l -> query(L, R), r -> query(L, R));
    }
    void set(int L, int R, int64_t x) {
        if (R <= lo || hi <= L) { return; }
        if (L <= lo && hi <= R) {
            mset = val = x, madd = 0;
        } else {
            push(), l -> set(L, R, x), r -> set(L, R, x);
            val = min(l -> val, r -> val);
        }
    }
    void add(int L, int R, int64_t x) {
        if (R <= lo || hi <= L) { return; }
        if (L <= lo && hi <= R) {
            if (mset != OO) {
                mset += x;
            } else {
                madd += x;
            }
            val += x;
        } else {
            push(), l -> add(L, R, x), r -> add(L, R, x);
            val = min(l -> val, r -> val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != OO) {
            l -> set(lo, hi, mset), r -> set(lo, hi, mset), mset = OO;
        } else if (madd) {
            l -> add(lo, hi, madd), r -> add(lo, hi, madd), madd = 0;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Node b(a, 0, n);
    int Q;
    cin >> Q;
    cin.ignore();
    while (Q--) {
        string s;
        getline(cin, s);
        if (count(s.begin(), s.end(), ' ') == 1) {
            stringstream sin(s);
            int l, r;
            sin >> l >> r;
            if (l <= r) {
                cout << b.query(l, r + 1) << "\n";
            } else {
                cout << min(b.query(l, n), b.query(0, r + 1)) << "\n";
            }
        } else {
            stringstream sin(s);
            int l, r;
            int64_t v;
            sin >> l >> r >> v;
            if (l <= r) {
                b.add(l, r + 1, v);
            } else {
                b.add(l, n, v);
                b.add(0, r + 1, v);
            }
        }
    }
}
