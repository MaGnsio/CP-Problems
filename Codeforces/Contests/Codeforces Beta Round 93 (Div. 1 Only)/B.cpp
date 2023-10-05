/**
 *    author:  MaGnsi0
 *    created: 18.04.2023 09:17:53
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) { j = pi[j - 1]; }
        pi[i] = j + (s[i] == s[j]);
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> pi = prefix_function(s);
    if (pi[n - 1] == 0) {
        cout << "Just a legend";
    } else if (count(pi.begin() + 1, pi.begin() + n - 1, pi[n - 1])) {
        cout << s.substr(0, pi[n - 1]);
    } else if (pi[pi[n - 1] - 1]) {
        cout << s.substr(0, pi[pi[n - 1] - 1]);
    } else {
        cout << "Just a legend";
    }
}
