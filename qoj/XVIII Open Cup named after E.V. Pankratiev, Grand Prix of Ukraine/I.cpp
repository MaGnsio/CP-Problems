/**
 *    author:  MaGnsi0
 *    created: 30.09.2023 22:36:58
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = N;
    cin >> n;
    vector<int> uballs(n);
    vector<vector<int>> box(n);
    vector<set<pair<int, int>>> have_color(N);
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        map<int, int> balls;
        for (int j = 0; j < m; ++j) {
            int color; cin >> color;
            balls[color]++;
        }
        uballs[i] = (int)balls.size();
        for (auto [color, count] : balls) {
            if (count > 1) {
                ans = min(ans, uballs[i] + 1);
            }
            box[i].push_back(color);
            have_color[color].emplace(uballs[i], (count == 1 ? i : -1));
        }
    }
    for (int first_box = 0; first_box < n; ++first_box) {
        vector<int> second_box;
        for (int color : box[first_box]) {
            second_box.push_back(N);
            for (auto [s, j] : have_color[color]) {
                if (j == first_box) { continue; }
                second_box.back() = s + 1;
                break;
            }
        }
        sort(second_box.rbegin(), second_box.rend());
        for (int j = 0; j < (int)second_box.size(); ++j) {
            ans = min(ans, second_box[j] + j);
        }
    }
    cout << ans;
}
