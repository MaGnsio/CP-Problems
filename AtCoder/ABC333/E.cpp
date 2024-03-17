/**
 *    author:  MaGnsi0
 *    created: 16.12.2023 14:21:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> potions, pot_time;
    vector<int> monster, mon_time;
    for (int t = 0; t < n; ++t) {
        int type; cin >> type;
        int x; cin >> x; x--;
        if (type == 1) {
            potions.push_back(x);
            pot_time.push_back(t);
        } else {
            monster.push_back(x);
            mon_time.push_back(t);
        }
    }
    int m = (int)potions.size();
    int k = (int)monster.size();
    vector<set<int>> have(n);
    for (int i = 0; i < m; ++i) {
        have[potions[i]].insert(-pot_time[i]);
    }
    vector<int> kill_mon(k);
    for (int i = k - 1; i >= 0; --i) {
        auto it = have[monster[i]].lower_bound(-mon_time[i]);
        if (it == have[monster[i]].end()) {
            cout << -1;
            return 0;
        }
        kill_mon[i] = -(*it);
        have[monster[i]].erase(it);
    }
    sort(kill_mon.begin(), kill_mon.end());
    int ans = 0, carried = 0;
    for (int i = 0, j = 0; i < k; ++i) {
        while (j < k && kill_mon[j] < mon_time[i]) {
            carried++, j++;
        }
        ans = max(ans, carried--);
    }
    cout << ans << "\n";
    set<int> used(kill_mon.begin(), kill_mon.end());
    for (int i = 0; i < m; ++i) {
        cout << (used.count(pot_time[i])) << " ";
    }
}
