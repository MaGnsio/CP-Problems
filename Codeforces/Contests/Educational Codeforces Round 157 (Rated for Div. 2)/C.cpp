/**
 *    author:  MaGnsi0
 *    created: 24.11.2023 14:40:00
**/
#include <bits/stdc++.h>

using namespace std;

int sum(string s) {
    int ans = 0;
    for (char c : s) {
        ans += c - '0';
    }
    return ans;
}

int F(string s, int k) {
    int n = (int)s.size();
    int m = n + k;
    if (m & 1) { return -1; }
    if (n < m / 2) { return -1; }
    int sum = 0;
    for (int i = 0; i < m / 2; ++i) {
        sum += s[i] - '0';
    }
    for (int i = m / 2; i < n; ++i) {
        sum -= s[i] - '0';
    }
    return sum;
}

int G(string s, int k) {
    int n = (int)s.size();
    int m = n + k;
    if (m & 1) { return -1; }
    if (n < m / 2) { return -1; }
    int sum = 0;
    for (int i = n - m / 2; i < n; ++i) {
        sum += s[i] - '0';
    }
    for (int i = 0; i < n - m / 2; ++i) {
        sum -= s[i] - '0';
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<map<int, int>> b(6);
    for (int i = 0; i < n; ++i) {
        b[(int)a[i].size()][sum(a[i])]++;
    }
    int64_t ans = 0, equals = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 1; k < 6; ++k) {
            int x = F(a[i], k);
            int y = G(a[i], k);
            if (k == (int)a[i].size()) {
                equals += b[k][x];
                equals += b[k][y];
            } else {
                ans += b[k][x];
                ans += b[k][y];
            }
        }
    }
    ans += equals / 2;
    cout << ans;
}
