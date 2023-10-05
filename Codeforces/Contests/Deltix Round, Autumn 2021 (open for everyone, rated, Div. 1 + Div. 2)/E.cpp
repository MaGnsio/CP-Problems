/**
 *    author:  MaGnsi0
 *    created: 28.11.2021 16:27:42
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e6;

struct segment_tree {
    int N, shift;
    string S;
    vector<int> index;
    vector<array<int, 6>> segTree;
    int L(int p) {
        return (p << 1);
    }
    int R(int p) {
        return (p << 1) + 1;
    }
    array<int, 6> compine(array<int, 6> a, array<int, 6> b) {
        array<int, 6> res;
        res[0] = a[0] + b[0]; //no. of letters to remove so sequence "a" can't be obtained
        res[1] = a[1] + b[1]; //no. of letters to remove so sequence "b" can't be obtained
        res[2] = a[2] + b[2]; //no. of letters to remove so sequence "c" can't be obtained
        res[3] = min(a[0] + b[3], a[3] + b[1]); //no. of letters to remove so sequence "ab" can't be obtained
        res[4] = min(a[1] + b[4], a[4] + b[2]); //no. of letters to remove so sequence "bc" can't be obtained
        res[5] = min({a[0] + b[5], a[3] + b[4], a[5] + b[2]}); //no. of letters to remove so sequence "abc" can't be obtained
        return res;
    }
    void build(int p, int l, int r) {
        if (l == r) {
            if (l < (int)S.size()) {
                index[l] = p;
                if (S[l] == 'a') {
                    segTree[p] = {1, 0, 0, 1, 0, 1};
                }
                if (S[l] == 'b') {
                    segTree[p] = {0, 1, 0, 0, 1, 0};
                }
                if (S[l] == 'c') {
                    segTree[p] = {0, 0, 1, 0, 0, 0};
                }
            }
        } else {
            int m = (l + r) / 2;
            build(L(p), l, m);
            build(R(p), m + 1, r);
            segTree[p] = compine(segTree[L(p)], segTree[R(p)]);
        }
    }
    void update(int p, char c) {
        p = index[p];
        if (c == 'a') {
            segTree[p] = {1, 0, 0, 1, 0, 1};
        }
        if (c == 'b') {
            segTree[p] = {0, 1, 0, 0, 1, 0};
        }
        if (c == 'c') {
            segTree[p] = {0, 0, 1, 0, 0, 0};
        }
        while (p > 1) {
            p /= 2;
            segTree[p] = compine(segTree[L(p)], segTree[R(p)]);
        }
    }
    int X() {
        return *min_element(segTree[1].begin(), segTree[1].end());
    }
    segment_tree(int n, string s) {
        N = n;
        S = s;
        index = vector<int>(N, -1);
        segTree = vector<array<int, 6>>(4 * N, {0, 0, 0, OO, OO});
        build(1, 0, N - 1);
        assert(count(index.begin(), index.end(), -1) == 0);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    string s;
    cin >> n >> q >> s;
    segment_tree a(n, s);
    for (int i = 0; i < q; ++i) {
        int k;
        char c;
        cin >> k >> c;
        k--;
        a.update(k, c);
        cout << a.X() << "\n";
    }
}
