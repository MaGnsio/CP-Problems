/**
 *    author:  MaGnsi0
 *    created: 04.05.2023 18:38:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> blocks;
    for (int i = 1, l = 0; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            blocks.emplace_back(l, i - 1);
            l = i;
        }
        if (i == n - 1) {
            blocks.emplace_back(l, i);
        }
    }
    int k = (int)blocks.size();
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        b[i] = min(blocks[i].second - blocks[i].first + 1, 2);
    }
    for (int i = 1; i < k; ++i) {
        b[i] += b[i - 1];
    }
    function<int(int, int)> F = [&](int l, int r) {
        int L = k, R = -1;
        {
            int low = 0, high = k - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (blocks[mid].first >= l) {
                    L = mid, high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (L == k || blocks[L].first > r) {
            return min(r - l + 1, 2);
        }
        {
            int low = L, high = k - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (blocks[mid].second <= r) {
                    R = mid, low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        if (R == -1) {
            assert(blocks[L].second > r);
            return min(r - blocks[L].first + 1, 2) + min(blocks[L].first - l, 2);
        }
        int ans = b[R] - (L ? b[L - 1] : 0);
        if (R + 1 < k && blocks[R + 1].first <= r) {
            ans += min(r - blocks[R + 1].first + 1, 2);
        }
        if (L && blocks[L - 1].second >= l) {
            ans += min(blocks[L - 1].second - l + 1, 2);
        }
        return ans;
    };
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        cout << F(l - 1, r - 1) << "\n";
    }
}
