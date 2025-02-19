/**
 *    author:  MaGnsi0
 *    created: 19.02.2025 23:48:46
**/
#include <bits/stdc++.h>

using namespace std;

const int A = 26;

string trim(string s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j && s[i] == s[j]) { i++, j--; }
    if (i > j) { return ""; }
    return s.substr(i, j - i + 1);
}

int F(string s, bool do_reverse = false) {
    if (s.empty()) { return 0; }
    if (do_reverse) {
        reverse(s.begin(), s.end());
    }
    int n = (int)s.size();
    int max_psuf = n / 2 - 1;
    while (max_psuf >= 0 && s[max_psuf] == s[n - max_psuf - 1]) { max_psuf--; }
    if (max_psuf == -1) { return 0; }
    vector f(A, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        f[s[i] - 'a'][i]++;
    }
    for (int j = 0; j < A; ++j) {
        for (int i = 1; i < n; ++i) {
            f[j][i] += f[j][i - 1];
        }
    }
    function<bool(int)> check = [&](int x) {
        if (x < n / 2 && max_psuf >= x) { return false; }
        int l = x < n / 2 ? n - x : x;
        for (int j = 0; j < A; ++j) {
            int f1 = f[j][n - 1] - f[j][l - 1];
            int f2 = f[j][x - 1];
            if (f1 > f2) { return false; }
        }
        return true;
    };
    int low = 2, high = n - 1, ans = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid; high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s; s = trim(s);
        int ans = min(F(s), F(s, true));
        cout << ans << "\n";
    }
}
