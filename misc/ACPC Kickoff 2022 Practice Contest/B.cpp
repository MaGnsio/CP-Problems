/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 16:06:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("files.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            int id;
            string s;
            cin >> s >> id;
            if (mp.count(s)) {
                mp[s] = min(mp[s], id);
            } else {
                mp[s] = id;
            }
        }
        vector<int> ids;
        for (auto& x : mp) {
            ids.push_back(x.second);
        }
        sort(ids.begin(), ids.end());
        for (int i = 0; i < (int)ids.size(); ++i) {
            cout << ids[i] << " ";
        }
        cout << "\n";
    }
}
