/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 02:49:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a, b;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int x = stoi(s.substr(0, (int)s.size() - 2)), y = s.back() - 'a';
        if (b.empty() || b.back() != y) {
            a.push_back(x);
            b.push_back(y);
        } else {
            a.back() += x;
        }
    }
    n = (int)a.size();
    vector<int64_t> c, d;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int x = stoi(s.substr(0, (int)s.size() - 2)), y = s.back() - 'a';
        if (d.empty() || d.back() != y) {
            c.push_back(x);
            d.push_back(y);
        } else {
            c.back() += x;
        }
    }
    m = (int)c.size();
    if (m == 1) {
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] == d[0] && a[i] >= c[0]) {
                ans += a[i] - c[0] + 1;
            }
        }
        cout << ans;
        return 0;
    }
    int k = n + m - 1;
    vector<int64_t> A, B;
    A.insert(A.end(), c.begin() + 1, c.begin() + m - 1);
    A.push_back(1);
    A.insert(A.end(), a.begin(), a.end());
    B.insert(B.end(), d.begin() + 1, d.begin() + m - 1);
    B.push_back(26);
    B.insert(B.end(), b.begin(), b.end());
    vector<int> pi(k);
    for (int i = 1; i < k; ++i) {
        int j = pi[i - 1];
        while (j && (A[i] != A[j] || B[i] != B[j])) { j = pi[j - 1]; }
        pi[i] = j + ((A[i] == A[j]) && (B[i] == B[j]));
    }
    int64_t ans = 0;
    for (int i = m - 1; i + 1 < k; ++i) {
        bool x = pi[i] == m - 2;
        bool y = A[i + 1] >= c[m - 1] && A[i - m + 2] >= c[0];
        bool z = B[i + 1] == d[m - 1] && B[i - m + 2] == d[0];
        ans += x && y && z;
    }
    cout << ans;
}
