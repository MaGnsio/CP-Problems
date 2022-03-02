/**
 *    author:  MaGnsi0
 *    created: 04.02.2022 02:38:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> creator(n);
    for (int i = 0; i < n; ++i) {
        cin >> creator[i];
        creator[i]--;
    }
    int p, q;
    cin >> p >> q;
    vector<vector<bool>> user_to_user(m, vector<bool>(m, false));
    for (int i = 0; i < p; ++i) {
        int x, y;
        cin >> x >> y;
        user_to_user[x - 1][y - 1] = true;
    }
    vector<vector<bool>> user_to_story(m, vector<bool>(n, false));
    vector<vector<bool>> user_story_by_user(m, vector<bool>(m, false));
    vector<vector<int>> story_followers(n);
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        user_to_story[x - 1][y - 1] = true;
        user_story_by_user[x - 1][creator[y - 1]] = true;
        story_followers[y - 1].push_back(x - 1);
    }
    vector<vector<bool>> same_follow(m, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)story_followers[i].size(); ++j) {
            for (int k = j + 1; k < (int)story_followers[i].size(); ++k) {
                same_follow[story_followers[i][j]][story_followers[i][k]] = true;
                same_follow[story_followers[i][k]][story_followers[i][j]] = true;
            }
        }
    }
    vector<vector<pair<int, int>>> scores(m, vector<pair<int, int>>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (creator[j] == i || user_to_story[i][j]) {
                scores[i][j] = {j, -1};
            } else {
                scores[i][j] = {j, 0};
                for (int k = 0; k < m; ++k) {
                    int a;
                    if (i == k) {
                        a = 0;
                    } else if (user_to_user[i][k]) {
                        a = 3;
                    } else if (user_story_by_user[i][k]) {
                        a = 2;
                    } else if (same_follow[i][k]) {
                        a = 1;
                    } else {
                        a = 0;
                    }
                    int b;
                    if (creator[j] == k) {
                        b = 2;
                    } else if (user_to_story[k][j]) {
                        b = 1;
                    } else {
                        b = 0;
                    }
                    scores[i][j].second += (a * b);
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        sort(scores[i].begin(), scores[i].end(), [](pair<int, int> a, pair<int, int> b) {
                return ((a.second > b.second) || (a.second == b.second && a.first < b.first));
           });
    }
    for (int i = 0; i < m; ++i) {
        cout << scores[i][0].first + 1 << " " << scores[i][1].first + 1 << " " << scores[i][2].first + 1 << "\n";
    }
}
