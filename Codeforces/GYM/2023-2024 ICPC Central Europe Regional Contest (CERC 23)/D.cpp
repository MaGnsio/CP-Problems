/**
 *    author:  MaGnsi0
 *    created: 13.01.2024 14:42:30
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 3e5 + 1;
bitset<N> dp(1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    int max_tfast = 0;
    vector<tuple<int, int, int64_t>> a;
    for (int i = 0; i < n; ++i) {
        int d; cin >> d;
        int tfast; cin >> tfast;
        int tslow; cin >> tslow;
        a.emplace_back(tslow, tfast, d);
        max_tfast = max(max_tfast, tfast);
    }
    sort(a.begin(), a.end());
    int64_t alld = 0, sumd = 0;
    for (int i = 0; i < n; ++i) {
        sumd += get<2>(a[i]);
        alld += get<2>(a[i]);
    }
    vector<int64_t> T, L;
    for (int i = 0; i < n; ++i) {
        if (max_tfast <= get<0>(a[i])) {
            T.push_back(get<0>(a[i]));
        }
        if (max_tfast <= get<1>(a[i])) {
            T.push_back(get<1>(a[i]));
        }
    }
    sort(T.begin(), T.end());
    int j = 0;
    for (int64_t t : T) {
        while (j < n && get<0>(a[j]) <= t) {
            sumd -= get<2>(a[j]);
            dp |= dp << get<2>(a[j]);
            j++;
        }
        int64_t sum = alld - sumd;
        int64_t add = (sum == 0 ? 0 : dp._Find_next((sum + 1) / 2 - 1));
        if (add == N) {
            L.push_back(N);
            continue;
        }
        int64_t l = sumd + add;
        L.push_back(l);
    }
    int m = (int)T.size();
    for (int i = 1; i < m; ++i) {
        assert(L[i] <= L[i - 1]);
    }
    while (Q--) {
        int64_t l; cin >> l;
        int low = 0, high = m - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (L[mid] <= l) {
                ans = T[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
