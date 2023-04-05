/**
 *    author:  MaGnsi0
 *    created: 25.12.2022 17:52:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        if (R[i] - L[i] >= k) {
            mp[0]++;
            mp[k]--;
            continue;
        }
        mp[L[i] % k]++;
        if ((R[i] % k) < (L[i] % k)) {
            mp[k]--;
            mp[0]++;
            mp[(R[i] % k) + 1]--;
        } else {
            mp[(R[i] % k) + 1]--;
        }
    }
    vector<int> a;
    for (auto& [x, y] : mp) {
        a.push_back(y);
    }
    for (int i = 1; i < (int)a.size(); ++i) {
        a[i] += a[i - 1];
    }
    int ans = *max_element(a.begin(), a.end());
    cout << ans;
}
