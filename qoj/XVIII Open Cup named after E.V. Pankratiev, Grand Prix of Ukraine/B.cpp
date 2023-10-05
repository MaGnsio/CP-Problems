/**
 *    author:  MaGnsi0
 *    created: 30.09.2023 15:05:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < m; ++i) {
        mp[a[i]]++;
    }
    int max_count = 0, max_card = 0;
    for (auto [x, y] : mp) {
        max_count = max(max_count, y);
        max_card = max(max_card, x);
    }
    vector<int> b;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            b.push_back(i);
            if (n != i * i) {
                b.push_back(n / i);
            }
        }
    }
    int good = 0;
    for (int d : b) {
        if (d < max_card) {
            continue;
        }
        if (n / d < max_count) {
            continue;
        }
        good++;
    }
    cout << (good == 1 ? "YES" : "NO");
}
