/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 20:39:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int ans; cin >> ans; ans--;
    vector<string> team(n);
    for (int i = 0; i < n; ++i) {
        cin >> team[i];
    }
    function<pair<int, int>()> get_p = [&]() {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (team[i][j] == 'P') {
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1);
    };
    function<void(int, int)> move_team = [&](int i, int d) {
        int ni = i - d;
        if (i == ans) {
            ans = ni;
        } else if (ni <= ans && ans < i) {
            ans++;
        }
        assert(ni >= 0);
        vector<string> new_team;
        for (int j = 0; j < n; ++j) {
            if (j == ni) {
                new_team.push_back(team[i]);
            }
            if (j != i) {
                new_team.push_back(team[j]);
            }
        }
        team = new_team;
    };
    while (get_p().first != -1) {
        string _; cin >> _;
        string res; cin >> res;
        auto [i, j] = get_p();
        if (res == "Aaawww...") {
            team[i][j] = 'R';
        } else {
            team[i][j] = 'A';
            int d = count(res.begin(), res.end(), 'y') - 3;
            move_team(i, d);
        }
    }
    cout << ans + 1;
}
