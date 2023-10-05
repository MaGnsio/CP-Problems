/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 01:21:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) { j = pi[j - 1]; }
        pi[i] = j + (s[i] == s[j]);
    }
    set<int> good;
    for (int i = pi[n - 1]; i > 0; i = pi[i - 1]) {
        good.insert(i);
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[pi[i]]++;
    }
    for (int i = n - 1; i > 0; --i) {
        b[pi[i - 1]] += b[i];
    }
    for (int i = 0; i < n; ++i) {
        b[i]++;
    }
    cout << good.size() + 1 << "\n";
    for (int i = 0; i < n; ++i) {
        if (good.count(i)) {
            cout << i << " " << b[i] << "\n";
        }
    }
    cout << n << " " << 1;
}
