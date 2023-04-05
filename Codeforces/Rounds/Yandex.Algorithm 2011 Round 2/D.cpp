/**
 *    author:  MaGnsi0
 *    created: 17.02.2023 15:00:51
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int block_size = sqrt(n) + 1;
    vector<int> l(t), r(t), e(t);
    for (int i = 0; i < t; ++i) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--, e[i] = i;
    }
    sort(e.begin(), e.end(), [&](int i, int j) {
            return make_pair(l[i] / block_size, r[i]) < make_pair(l[j] / block_size, r[j]);
        });
    int64_t sum = 0;
    vector<int64_t> cnt(N, 0), ans(t);
    function<void(int)> add = [&](int j) {
        if (j < 0 || j >= n) { return; }
        sum -= cnt[a[j]] * cnt[a[j]] * a[j];
        cnt[a[j]]++;
        sum += cnt[a[j]] * cnt[a[j]] * a[j];
    };
    function<void(int)> remove = [&](int j) {
        if (j < 0 || j >= n) { return; }
        sum -= cnt[a[j]] * cnt[a[j]] * a[j];
        cnt[a[j]]--;
        sum += cnt[a[j]] * cnt[a[j]] * a[j];
    };
    int cur_l = -1, cur_r = -1;
    for (int i = 0; i < t; ++i) {
        int j = e[i];
        while (cur_l > l[j]) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < r[j]) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < l[j]) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > r[j]) {
            remove(cur_r);
            cur_r--;
        }
        ans[j] = sum;
    }
    for (int i = 0; i < t; ++i) {
        cout << ans[i] << "\n";
    }
}
