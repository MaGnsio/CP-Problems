/**
 *    author:  MaGnsi0
 *    created: 18.07.2023 23:33:09
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    int x = 0, y = 0;
    vector<int> cnt(N);
    vector<bool> done(n, false);
    for (int i = 0; i < n; ++i) {
        if (done[i]) { continue; }
        int length = 0;
        for (int j = i; !done[j]; j = a[j]) {
            done[j] = true;
            length++;
        }
        cnt[length]++;
        x += length / 2;
        y += length % 2;
    }
    bitset<N> dp(0);
    dp[0] = true;
    for (int i = 0; i < N; ++i) {
        if (cnt[i] == 0) { continue; }
        for (int j = 1; ; j *= 2) {
            j = min(j, cnt[i]);
            int take = j * i;
            dp |= (dp << take), cnt[i] -= j;
            if (cnt[i] <= 0) { break; }
        }
    }
    int ans_min = (dp[k] ? k : k + 1);
    int ans_max = 2 * min(k, x);
    k -= min(k, x), ans_max += min(k, y);
    cout << ans_min << " " << ans_max;
}
