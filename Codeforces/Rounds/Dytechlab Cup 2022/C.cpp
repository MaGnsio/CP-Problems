/**
 *    author:  MaGnsi0
 *    created: 07.10.2022 17:55:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(3);
        for (int i = 0; i < 3; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        int x, y;
        cin >> x >> y;
        sort(a.begin(), a.end());
        bool can = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                if (a[i].first == a[j].first) {
                    can |= x == a[i].first;
                }
                if (a[i].second == a[j].second) {
                    can |= y == a[i].second;
                }
            }
        }
        if (can) {
            cout << "YES\n";
            continue;
        }
        vector<pair<int, int>> c1 = {{1, 1}, {1, 2}, {2, 1}};
        sort(c1.begin(), c1.end());
        vector<pair<int, int>> c2 = {{1, n}, {1, n - 1}, {2, n}};
        sort(c2.begin(), c2.end());
        vector<pair<int, int>> c3 = {{n, 1}, {n, 2}, {n - 1, 1}};
        sort(c3.begin(), c3.end());
        vector<pair<int, int>> c4 = {{n, n}, {n, n - 1}, {n - 1, n}};
        sort(c4.begin(), c4.end());
        if (a == c1) {
            bool can = false;
            a.push_back({3, 1});
            a.push_back({1, 3});
            for (int i = 0; i < 5; ++i) {
                can |= (a[i].first == x && a[i].second == y);
            }
            cout << (can ? "YES" : "NO") << "\n";
            continue;
        }
        if (a == c2) {
            bool can = false;
            a.push_back({1, n - 2});
            a.push_back({3, n});
            for (int i = 0; i < 5; ++i) {
                can |= (a[i].first == x && a[i].second == y);
            }
            cout << (can ? "YES" : "NO") << "\n";
            continue;
        }
        if (a == c3) {
            bool can = false;
            a.push_back({n - 2, 1});
            a.push_back({n, 3});
            for (int i = 0; i < 5; ++i) {
                can |= (a[i].first == x && a[i].second == y);
            }
            cout << (can ? "YES" : "NO") << "\n";
            continue;
        }
        if (a == c4) {
            bool can = false;
            a.push_back({n - 2, n});
            a.push_back({n, n - 2});
            for (int i = 0; i < 5; ++i) {
                can |= (a[i].first == x && a[i].second == y);
            }
            cout << (can ? "YES" : "NO") << "\n";
            continue;
        }
        for (int i = 0; i < 3; ++i) {
            can |= (a[i].first % 2 == x % 2 && a[i].second % 2 == y % 2);
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
}
