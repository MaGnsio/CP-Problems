/**
 *    author:  MaGnsi0
 *    created: 05.06.2023 03:25:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    if (n & 1) {
        for (int i = 0; i < m; ++i) {
            int _; cin >> _;
            cout << "NO\n";
        }
        return 0;
    }
    set<int> a, b;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1] && s[i] == '(') { a.insert(i); }
        if (s[i] == s[i + 1] && s[i] == ')') { b.insert(i); }
    }
    for (int i = 0; i < m; ++i) {
        int j;
        cin >> j;
        j--;
        if (j && s[j - 1] == s[j] && s[j - 1] == '(') { a.erase(j - 1); }
        if (j && s[j - 1] == s[j] && s[j - 1] == ')') { b.erase(j - 1); }
        if (j + 1 < n && s[j] == s[j + 1] && s[j] == '(') { a.erase(j); }
        if (j + 1 < n && s[j] == s[j + 1] && s[j] == ')') { b.erase(j); }
        s[j] = (s[j] == '(' ? ')' : '(');
        if (j && s[j - 1] == s[j] && s[j - 1] == '(') { a.insert(j - 1); }
        if (j && s[j - 1] == s[j] && s[j - 1] == ')') { b.insert(j - 1); }
        if (j + 1 < n && s[j] == s[j + 1] && s[j] == '(') { a.insert(j); }
        if (j + 1 < n && s[j] == s[j + 1] && s[j] == ')') { b.insert(j); }
        if (s[0] == ')' || s[n - 1] == '(') {
            cout << "NO\n";
        } else if (a.empty() && b.empty()) {
            cout << "YES\n";
        } else if (a.empty() || b.empty()) {
            cout << "NO\n";
        } else {
            cout << (*a.begin() < *b.begin() && *a.rbegin() < *b.rbegin() ? "YES" : "NO") << "\n";
        }
    }
}
