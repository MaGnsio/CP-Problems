/**
 *    author:  MaGnsi0
 *    created: 04.10.2022 19:05:14
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        function<vector<int>(int)> solve = [&](int diff) {
            vector<int> c(n, -1);
            map<int, vector<int>> d1, d2;
            for (int i = 0; i < n; ++i) {
                d1[a[i]].push_back(i);
                d2[b[i]].push_back(i);
            }
            while (!d1.empty()) {
                int i = (*d1.rbegin()).second.back();
                int j = (*d2.rbegin()).second.back();
                int max_d1 = a[i];
                int max_d2 = b[j];
                if (max_d1 <= diff && max_d2 <= diff) { break; }
                if (max_d1 > max_d2) {
                    if (d2.count(max_d1 - diff) == 0) { return c; }
                    int k = d2[max_d1 - diff].back();
                    c[i] = k;
                    d1[max_d1].pop_back();
                    if (d1[max_d1].empty()) {
                        d1.erase(max_d1);
                    }
                    d2[b[k]].pop_back();
                    if (d2[b[k]].empty()) {
                        d2.erase(b[k]);
                    }
                } else {
                    if (d1.count(max_d2 - diff) == 0) { return c; }
                    int k = d1[max_d2 - diff].back();
                    c[k] = j;
                    d1[a[k]].pop_back();
                    if (d1[a[k]].empty()) {
                        d1.erase(a[k]);
                    }
                    d2[max_d2].pop_back();
                    if (d2[max_d2].empty()) {
                        d2.erase(max_d2);
                    }
                }
            }
            for (auto& [x, _] : d1) {
                for (auto& i : _) {
                    if (d2.count(diff - x) == 0) { return c; }
                    int j = d2[diff - x].back();
                    c[i] = j;
                    d2[b[j]].pop_back();
                    if (d2[b[j]].empty()) {
                        d2.erase(b[j]);
                    }
                }
            }
            return c;
        };
        int x = -1;
        vector<int> c(n, -1);
        for (int i = 0; i < n; ++i) {
            vector<int> c1 = solve(a[0] + b[i]);
            vector<int> c2 = solve(abs(a[0] - b[i]));
            if (count(c1.begin(), c1.end(), -1) == 0) {
                x = a[0] + b[i];
                c = c1;
                break;
            }
            if (count(c2.begin(), c2.end(), -1) == 0) {
                x = abs(a[0] - b[i]);
                c = c2;
                break;
            }
        }
        if (x == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int p1 = 0, p2 = x;
            for (int i = 0; i < n; ++i) {
                int d1 = a[i], d2 = b[c[i]];
                if (d1 + d2 == x) {
                    //do nothing
                } else if (d1 > d2) {
                    p1 += max(0, d2 - p2);
                    p2 += max(0, d2 - p2);
                } else {
                    p2 += max(0, d1 - p1);
                    p1 += max(0, d1 - p1);
                }
            }
            for (int i = 0; i < n; ++i) {
                int d1 = a[i], d2 = b[c[i]];
                if (d1 + d2 == x) {
                    cout << p1 + d1 << " ";
                } else if (d1 > d2) {
                    cout << p1 + d1 << " ";
                } else {
                    cout << p2 - d2 << " ";
                }
            }
            cout << "\n";
            cout << p1 << " " << p2 << "\n";
        }
    }
}
