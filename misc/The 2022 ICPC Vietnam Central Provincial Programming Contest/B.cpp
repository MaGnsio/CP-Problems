/**
 *    author:  MaGnsi0
 *    created: 16.09.2023 12:33:05
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> pi = prefix_function(s);
    vector<bool> good(n + 1, false);
    for (int j = pi[n - 1]; j > 0; j = pi[j - 1]) {
        good[j] = true;
    }
    vector<int> ans(n + 1);
    for (int i = 0; i < n; ++i) {
        ans[pi[i]]++;
    }
    for (int i = n-1; i > 0; --i) {
        ans[pi[i - 1]] += ans[i];
    }
    for (int i = 0; i <= n; ++i) {
        ans[i]++;
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int m;
        cin >> m;
        if (!good[m] || ans[m] < 3) {
            cout << "NO\n";
        } else {
            cout << "YES " << ans[m] << "\n";
        }
    }
}
