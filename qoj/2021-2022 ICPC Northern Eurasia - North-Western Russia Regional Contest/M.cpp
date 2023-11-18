/**
 *    author:  MaGnsi0
 *    created: 27.09.2023 21:05:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> l(n);
    vector<vector<pair<string, int>>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        a[i].resize(l[i]);
        for (int j = 0; j < l[i]; ++j) {
            string in; cin >> in;
            for (int k = 0; k < (int)in.size(); ++k) {
                if (in[k] == '=') {
                    assert(k);
                    string name = in.substr(0, k);
                    int val = stoi(in.substr(k + 1));
                    a[i][j] = {name, val};
                    break;
                }
            }
        }
    }
    int m;
    cin >> m;
    map<string, int> mp;
    for (int i = 0; i < m; ++i) {
        string x; cin >> x;
        int val; cin >> val;
        mp[x] = val;

    }
    vector<int> ans;
    set<string> done;
    while (true) {
        bool all_done = true;
        for (int i = 0; i < n; ++i) {
            all_done = all_done && l[i] == 0;
        }
        if (all_done) { break; }
        bool all_good = false;
        for (int i = 0; i < n; ++i) {
            if (l[i] == 0) { continue; }
            if (done.count(a[i][l[i] - 1].first)) {
                ans.push_back(i + 1);
                all_good = true;
                l[i]--;
                break;
            } else if (mp[a[i][l[i] - 1].first] == a[i][l[i] - 1].second) {
                ans.push_back(i + 1);
                done.insert(a[i][l[i] - 1].first);
                all_good = true;
                l[i]--;
                break;
            }
        }
        if (!all_good) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    reverse(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << " ";
    }
}
