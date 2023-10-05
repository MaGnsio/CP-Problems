/**
 *    author:  MaGnsi0
 *    created: 14/06/2021 03:45:31
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, maxi = 0, ans = INT_MAX;
    cin >> n;
    vector<int> v(n);
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    for (int i = 0; i < n; ++i) {
        int temp = v[i], cnt = 0;
        while (temp) {
            if ((temp & 1) && (temp > 1)) {
                int x = temp / 2, y = cnt + 1;
                while (x <= maxi) {
                    x *= 2;
                    y++;
                    m[x].push_back({i, y});
                }
            }
            temp /= 2;
            cnt++;
            m[temp].push_back({i, cnt});
        }
        temp = v[i], cnt = 0;
        while (temp <= maxi) {
            temp *= 2;
            cnt++;
            m[temp].push_back({i, cnt});
        }
        m[v[i]].push_back({i, 0});
    }
    for (auto& [a, b] : m) {
        if (b.size() == n) {
            int temp = 0;
            for (auto& [x, y] : b) {
                temp += y;
            }
            ans = min(ans, temp);
        }
    }
    cout << ans;
}
