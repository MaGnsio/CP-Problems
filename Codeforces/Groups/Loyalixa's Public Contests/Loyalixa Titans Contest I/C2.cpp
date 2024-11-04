/**
 *    author:  MaGnsi0
 *    created: 04.11.2024 19:49:19
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> A(N);

struct SQ {
    int S, B;
    vector<int> I, V;
    vector<vector<int>> blocks;
    SQ() {}
    SQ(vector<int> I) {
        if (I.empty()) { return; }
        S = (int)I.size();
        B = (int)sqrt(S) + 1;
        this -> I = I;
        blocks.resize(B);
        for (int i = 0; i < S; ++i) {
            blocks[b(i)].push_back(A[I[i]]);
        }
        for (int i = 0; i < B; ++i) {
            sort(blocks[i].begin(), blocks[i].end());
        }
    }
    int b(int i) { assert(B); return i / B; }
    int count_block(int bi, int s, int e) {
        return upper_bound(blocks[bi].begin(), blocks[bi].end(), e) - lower_bound(blocks[bi].begin(), blocks[bi].end(), s);
    }
    int count_block_range(int bi, int bs, int be, int s, int e) {
        int c = 0;
        while (bs <= be && b(bs) == bi) {
            int val = A[I[bs]];
            c += s <= val && val <= e;
            bs++;
        }
        return c;
    }
    int solve_block(int k, int bi, int bs, int be, int s, int e) {
        while (bs <= be && b(bs) == bi) {
            int val = A[I[bs]];
            k -= s <= val && val <= e;
            if (k == 0) { return I[bs]; }
            bs++;
        }
        return -1;
    }
    int solve(int k, int l, int r, int s, int e) {
        if (l > r) { return -1; }
        if (s > e) { return -1; }
        if (I.empty()) { return -1; }
        l = lower_bound(I.begin(), I.end(), l) - I.begin();
        r = upper_bound(I.begin(), I.end(), r) - I.begin() - 1;
        if (l > r) { return -1; }
        if (b(l) == b(r)) { return solve_block(k, b(l), l, r, s, e); }
        int first_block = solve_block(k, b(l), l, N, s, e);
        if (first_block != -1) { return first_block; }
        k -= count_block_range(b(l), l, N, s, e);
        for (int bi = b(l) + 1; bi < b(r); ++bi) {
            int c = count_block(bi, s, e);
            if (c >= k) { return solve_block(k, bi, B * bi, N, s, e); }
            k -= c;
        }
        return solve_block(k, b(r), B * b(r), r, s, e);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    vector<vector<int>> F(N);
    for (int i = 1; i <= n; ++i) {
        F[A[i]].push_back(i);
    }
    vector<SQ> RQ(N);
    for (int x = 1; x < N; ++x) {
        for (int y = 2 * x; y < N; y += x) {
            F[x].insert(F[x].end(), F[y].begin(), F[y].end());
        }
        sort(F[x].begin(), F[x].end());
        RQ[x] = SQ(F[x]);
    }
    int Q; cin >> Q;
    while (Q--) {
        int x; cin >> x;
        int k; cin >> k;
        int s; cin >> s;
        int e; cin >> e;
        int l; cin >> l;
        int r; cin >> r;
        cout << RQ[x].solve(k, l, r, s, e) << "\n";
    }
}
