/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 21:01:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("bracket.in", "r", stdin);
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<vector<bool>> good(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        stack<char> _s;
        for (int j = i; j < n; ++j) {
            if (s[j] == ')' && _s.empty()) {
                break;
            }
            if (s[j] == '(') {
                _s.push(s[j]);
            } else {
                _s.pop();
            }
            if (_s.empty()) {
                good[i][j] = true;
            }
        }
    }
    auto work = [&]() {
        vector<int> L(m), R(m);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int x = a[cur].first;
            int j = a[cur].second;
            if (i + x - 1 >= n) {
                return false;
            }
            if (good[i][i + x - 1]) {
                L[j] = i + 1;
                R[j] = i + x;
                i = i + x - 2;
                cur++;
            }
            if (cur == m) {
                break;
            }
        }
        if (cur < m) {
            return false;
        } else {
            cout << "YES\n";
            for (int i = 0; i < m; ++i) {
                cout << L[i] << " " << R[i] << "\n";
            }
            return true;
        }
    };
    do {
        if (work()) {
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << "NO";
}
