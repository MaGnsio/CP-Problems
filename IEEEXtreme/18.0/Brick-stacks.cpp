/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 23:01:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x; cin >> x;
    set<int> S_;
    map<int, int> S;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; S[x]++;
        S_.insert(x);
    }
    vector<vector<int>> stacks;
    while (!S_.empty()) {
        int val = *S_.begin();
        S[val]--;
        if (!S[val]) {
            S_.erase(val);
        }
        stacks.push_back({val});
        while (true) {
            if (val + x > 1e9) { break; }
            auto it = S_.lower_bound(val + x);
            if (it == S_.end()) { break; }
            val = *it;
            S[val]--;
            if (!S[val]) {
                S_.erase(val);
            }
            stacks.back().push_back(val);
        }
    }
    cout << (int)stacks.size() << "\n";
    for (auto& s : stacks) {
        reverse(s.begin(), s.end());
        cout << (int)s.size();
        for (int e : s) { cout << " " << e; }
        cout << "\n";
    }
}
