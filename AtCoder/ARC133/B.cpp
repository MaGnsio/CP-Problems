/**
 *    author:  MaGnsi0
 *    created: 22.06.2023 14:53:50
**/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<pair<int, int>> A) {
    int n = A.size(), k = 0;
    vector<int> L(n, 0), memo(n, 0);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, -A[i].second) - L.begin();
        L[pos] = -A[i].second;
        if (pos == k) { k++; }
        memo[i] = pos + 1;
    }
    int ans = *max_element(memo.begin(), memo.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        c[a[i]] = i;
    }
    vector<pair<int, int>> d;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= b[i]; ++j) {
            if (b[i] % j == 0) {
                d.emplace_back(c[j], -i);
                if (b[i] == j * j) { continue; }
                d.emplace_back(c[b[i] / j], -i);
            }
        }
    }
    sort(d.begin(), d.end());
    int ans = solve(d);
    cout << ans;
}
