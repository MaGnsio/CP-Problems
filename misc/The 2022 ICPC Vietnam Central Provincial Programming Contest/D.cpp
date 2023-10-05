/**
 *    author:  MaGnsi0
 *    created: 16.09.2023 11:57:47
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 320;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> L(q), R(q), I(q);
    for (int i = 0; i < q; ++i) {
        cin >> L[i] >> R[i];
        L[i]--, R[i]--, I[i] = i;
    }
    sort(I.begin(), I.end(), [&](int i, int j) {
            return make_pair(L[i] / M, R[i]) < make_pair(L[j] / M, R[j]);
        });
    vector<int> b(N), c(M), ans(q);
    function<void(int)> add = [&](int j) {
        if (j < 0 || j >= n) { return; }
        b[a[j]]++, c[a[j] / M]++;
    };
    function<void(int)> remove = [&](int j) {
        if (j < 0 || j >= n) { return; }
        b[a[j]]--, c[a[j] / M]--;
    };
    int cur_l = -1, cur_r = -1;
    for (int i = 0; i < q; ++i) {
        int j = I[i];
        while (cur_l > L[j]) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < R[j]) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < L[j]) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > R[j]) {
            remove(cur_r);
            cur_r--;
        }
        int want = (R[j] - L[j] + 2) / 2, have = 0, block = -1;
        for (int k = 0; k < M; ++k) {
            if (have + c[k] >= want) {
                block = k;
                break;
            }
            have += c[k];
        }
        assert(block != -1);
        for (int k = block * M, _ = 0; k < N && _ < M; ++k, ++_) {
            if (have + b[k] >= want) {
                ans[j] = k;
                break;
            }
            have += b[k];
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}
