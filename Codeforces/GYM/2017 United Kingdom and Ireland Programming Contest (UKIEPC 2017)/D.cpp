/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 19:37:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    string t = s;
    sort(t.begin(), t.end());
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if (t[i] == s[i]) {
            continue;
        }
        for (int j = i + 1; j < n; ++j) {
            if (t[j] == s[i]) {
                if (t[j] > t[i]) {
                    ans.emplace_back(j + 1, i + 1);
                } else {
                    ans.emplace_back(i + 1, j + 1);
                }
                swap(t[i], t[j]);
                break;
            }
        }
    }
    for (auto& [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
}
