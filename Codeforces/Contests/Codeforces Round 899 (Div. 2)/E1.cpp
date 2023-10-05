/**
 *    author:  MaGnsi0
 *    created: 25.09.2023 18:17:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    function<void(vector<int>&, int)> OP = [](vector<int>& a, int j) {
        int k = (int)a.size();
        vector<int> new_a;
        for (int i = j + 1; i < k; ++i) {
            new_a.push_back(a[i]);
        }
        new_a.push_back(a[j]);
        for (int i = 0; i < j; ++i) {
            new_a.push_back(a[i]);
        }
        a = new_a;
    };
    vector<int> ans_a, ans_b;
    for (int last = 1; last <= n; ++last) {
        int j = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == last) {
                j = i;
                break;
            }
        }
        if (j == n - 1) { continue; }
        if (last == 1) {
            OP(a, j + 1);
            ans_a.push_back(j + 2);
        } else {
            OP(a, j);
            ans_a.push_back(j + 1);
            if (n - j < n) {
                OP(a, n - j); 
                ans_a.push_back(n - j + 1);
            }
        }
    }
    for (int last = 1; last <= m; ++last) {
        int j = -1;
        for (int i = 0; i < m; ++i) {
            if (b[i] == last) {
                j = i;
                break;
            }
        }
        if (j == m - 1) { continue; }
        if (last == 1) {
            OP(b, j + 1);
            ans_b.push_back(j + 2);
        } else {
            OP(b, j);
            ans_b.push_back(j + 1);
            if (m - j < m) {
                OP(b, m - j); 
                ans_b.push_back(m - j + 1);
            }
        }
    }
    int X = (int)ans_a.size(), Y = (int)ans_b.size();
    if ((abs(X - Y) & 1)) {
        if (n & 1) {
            for (int i = 0; i < n; ++i) {
                ans_a.push_back(1);
            }
        } else if (m & 1) {
            for (int i = 0; i < m; ++i) {
                ans_b.push_back(1);
            }
        } else {
            cout << -1;
            return 0;
        }
    }
    X = (int)ans_a.size(), Y = (int)ans_b.size();
    if (X < Y) {
        for (int i = 0; i < abs(X - Y); i += 2) {
            ans_a.push_back(1);
            ans_a.push_back(n);
        }
    } else if (Y < X) {
        for (int i = 0; i < abs(X - Y); i += 2) {
            ans_b.push_back(1);
            ans_b.push_back(m);
        }
    }
    cout << max(X, Y) << "\n";
    for (int i = 0; i < max(X, Y); ++i) {
        cout << ans_a[i] << " " << ans_b[i] << "\n";
    }
}
