/**
 *    author:  MaGnsi0
 *    created: 06.06.2022 06:09:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<string, vector<string>> mp;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    for (auto& [s, a] : mp) {
        for (int i = 0; i + 4 < (int)a.size(); ++i) {
            set<string> kills = {a[i], a[i + 1], a[i + 2], a[i + 3], a[i + 4]};
            if ((int)kills.size() == 5) {
                cout << "PENTA KILL!";
                return 0;
            }
        }
    }
    cout << "SAD:(";
}
