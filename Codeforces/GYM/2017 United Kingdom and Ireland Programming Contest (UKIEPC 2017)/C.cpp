/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 19:33:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string, int> mp = {{"red", 1}, {"yellow", 2}, {"green", 3}, {"brown", 4}, {"blue", 5}, {"pink", 6}, {"black", 7}};
    int n, red_cnt = 0;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (mp[s] == 1) {
            red_cnt++;
        } else {
            a.push_back(mp[s]);
        }
    }
    if (a.empty()) {
        cout << (red_cnt != 0);
        return 0;
    }
    int max_ball = *max_element(a.begin(), a.end());
    int ans = (red_cnt + 1) * max_ball + red_cnt + accumulate(a.begin(), a.end(), 0) - max_ball;
    cout << ans;
}
