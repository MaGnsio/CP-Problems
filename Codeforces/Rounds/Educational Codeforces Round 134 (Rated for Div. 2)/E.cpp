/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 03:45:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> pi(n);
    vector<vector<int>> aut(n, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i > 0 && s[i] - 'a' != j) {
                aut[i][j] = aut[pi[i - 1]][j];
            } else {
                aut[i][j] = i + (s[i] - 'a' == j);
            }
        }
        pi[i] = (i ? aut[pi[i - 1]][s[i] - 'a'] : 0);
    }
    int T;
    cin >> T;
    while (T--) {
        string t;
        cin >> t;
        int m = (int)t.size();
        s += t;
        for (int i = n; i < n + m; ++i) {
            aut.push_back(vector<int>(26));
            for (int j = 0; j < 26; ++j) {
                if (i > 0 && s[i] - 'a' != j) {
                    aut[i][j] = aut[pi[i - 1]][j];
                } else {
                    aut[i][j] = i + (s[i] - 'a' == j);
                }
            }
            pi.push_back(aut[pi[i - 1]][s[i] - 'a']);
        }
        for (int i = n; i < n + m; ++i) {
            cout << pi[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < m; ++i) {
            s.pop_back();
            pi.pop_back();
            aut.pop_back();
        }
    }
}
