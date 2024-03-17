/**
 *    author:  MaGnsi0
 *    created: 26.02.2024 12:29:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    cin.ignore();
    vector<vector<int>> cp(n);
    vector<map<int, int>> cpm(n);
    for (int i = 0; i < n; ++i) {
        string s, in; getline(cin, s);
        stringstream sin(s);
        while (sin >> in) {
            int j = stoi(in) - 1;
            cp[i].push_back(j);
            cpm[i][j] = (int)cp[i].size() - 1;
        }
    }
    vector<vector<int>> rp(m);
    vector<map<int, int>> rpm(m);
    for (int j = 0; j < m; ++j) {
        string s, in; getline(cin, s);
        stringstream sin(s);
        while (sin >> in) {
            if (in == "0") { break; }
            int i = stoi(in) - 1;
            rp[j].push_back(j);
            rpm[j][i] = (int)rp[j].size() - 1;
        }
    }
    queue<int> Q;
    vector<bool> is_set(n, false);
    vector<int> cur_preference(n, 0);
    vector<set<pair<int, int>>> now_set(m);
    for (int i = 0; i < n; ++i) {
        Q.push(i);
    }
    while (!Q.empty()) {
        int i = Q.front(); Q.pop();
        int j = cp[i][cur_preference[i]];
        cur_preference[i]++;
        if (now_set[j].size() == c[j]) {
            if (-now_set[j].begin() -> first > rpm[j][i]) {
                int move = now_set[j].begin() -> second;
                now_set[j].erase(now_set[j].begin());
                is_set[move] = false, is_set[i] = true;
                if (cur_preference[move] < (int)cp[move].size()) {
                    Q.push(move);
                }
                now_set[j].emplace(-rpm[j][i], i);
            } else {
                if (cur_preference[i] < (int)cp[i].size()) {
                    Q.push(i);
                }
            }
        } else {
            is_set[i] = true;
            now_set[j].emplace(-rpm[j][i], i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (is_set[i]) {
            cout << i + 1 << "\n";
        }
    }
}
