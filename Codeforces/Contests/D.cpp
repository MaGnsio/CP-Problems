/**
 *    author:  MaGnsi0
 *    created: 13.09.2024 21:08:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (n <= 600) {
            map<string, int> mp;
            for (int j = 0; j < m; ++j) {
                string ones = "";
                for (int i = 0; i < n; ++i) {
                    ones += a[i][j];
                }
                for (int i = 0; i < n; ++i) {
                    if (a[i][j] == '0') {
                        string val = ones; val[i] = '1';
                        mp[val]++;
                    } else {
                        string val = ones; val[i] = '0';
                        mp[val]++;
                    }
                }
            }
            pair<int, string> ans = {-1, ""};
            for (auto [mask, val] : mp) {
                ans = max(ans, make_pair(val, mask));
            }
            cout << ans.first << "\n";
            cout << ans.second << "\n";
        } else {
            map<string, int> similar;
            for (int j = 0; j < m; ++j) {
                string ones = "";
                for (int i = 0; i < n; ++i) {
                    ones += a[i][j];
                }
                similar[ones]++;
            }
            vector<pair<string, int>> b;
            pair<int, string> ans = {-1, ""};
            for (auto p : similar) {
                b.push_back(p);
            }
            for (int i = 0; i < (int)b.size(); ++i) {
                bool have_one = false;
                string mask = "";
                for (int k = 0; k < n; ++k) {
                    if (b[i].first[k] == '1') {
                        mask += have_one ? '1' : '0';
                        have_one = true;
                    } else {
                        mask += b[i].first[k];
                    }
                }
                if (have_one == false) {
                    mask[0] = '1';
                }
                ans = max(ans, make_pair(b[i].second, mask));
                for (int j = i + 1; j < (int)b.size(); ++j) {
                    int diffs = 0;
                    for (int k = 0; k < n; ++k) {
                        diffs += b[i].first[k] != b[j].first[k];
                    }
                    if (diffs != 2) { continue; }
                    int sum = 0;
                    bool have_one = false;
                    string mask = "";
                    for (int k = 0; k < n; ++k) {
                        if (b[i].first[k] == '1' && b[j].first[k] == '1') {
                            mask += '1';
                        } else if (b[i].first[k] == '0' && b[j].first[k] == '0') {
                            mask += '0';
                        } else {
                            sum += b[i].first[k] - '0';
                            mask += (have_one ? '1' : '0');
                            have_one = true;
                        }
                    }
                    if (sum != 1) { continue; }
                    ans = max(ans, make_pair(b[i].second + b[j].second, mask));
                }
            }
            cout << ans.first << "\n";
            cout << ans.second << "\n";
        }
    }
}
