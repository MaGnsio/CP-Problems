/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 18:15:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> a;
    for (auto& [_, x] : mp) {
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int ans = (int)a.size();
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i] <= k) {
            k -= a[i];
            ans--;
        }
    }
    cout << ans;
}
