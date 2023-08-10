#include <bits/stdc++.h>

using namespace std;

int F(vector<vector<int>> a) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (a[i][j] == -1) { continue; }
            if (i && i + 1 < 4 && a[i][j] == a[i - 1][j] && a[i][j] == a[i + 1][j]) {
                return 1;
            }
            if (j && j + 1 < 4 && a[i][j] == a[i][j - 1] && a[i][j] == a[i][j + 1]) {
                return 1;
            }
            if (i && j && i + 1 < 4 && j + 1 < 4 && a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i + 1][j + 1]) {
                return 1;
            }
            if (i && j && i + 1 < 4 && j + 1 < 4 && a[i][j] == a[i - 1][j + 1] && a[i][j] == a[i + 1][j - 1]) {
                return 1;
            }
        }
    }
    bool filled = true;
    for (int i = 0; i < 4; ++i) {
        filled = filled && count(a[i].begin(), a[i].end(), -1) == 0;
    }
    return (filled ? 2 : 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, a, b;
    cin >> x >> a >> b;
    x--, a--, b--;
    vector<vector<int>> s(4, vector<int>(4, -1));
    int ans = 0;
    set<vector<vector<int>>> visited;
    function<void(int)> solve = [&](int turn) {
        if (s[a][b] != -1 || F(s) || visited.count(s)) {
            return;
        }
        visited.insert(s);
        vector<int> p(4, -1);
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                if (s[i][j] == -1) {
                    p[j] = i;
                    break;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (p[i] == -1) { continue; }
            if (a == p[i] && b == i) {
                if (turn == 0) { continue; }
                s[a][b] = 1;
                if (F(s) == 1) {
                    ans++;
                }
                s[a][b] = -1;
            } else {
                s[p[i]][i] = turn;
                solve(turn ^ 1);
                s[p[i]][i] = -1;
            }
        }
    };
    s[0][x] = 0;
    solve(1);
    cout << ans;
}
