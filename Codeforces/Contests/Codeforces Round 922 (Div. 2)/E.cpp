/**
 *    author:  MaGnsi0
 *    created: 30.01.2024 20:26:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    function<char(int)> ask = [&](int i) {
        cout << "? " << i + 1 << endl;
        char c; cin >> c; return c;
    };
    function<vector<int>(vector<int>)> solve = [&](vector<int> I) {
        if (I.size() <= 1) { return I; }
        shuffle(I.begin(), I.end(), rng);
        int j = I.back(); I.pop_back();
        while (ask(j) != '=');
        vector<int> L, R;
        for (int i : I) {
            if (ask(i) == '<') {
                L.push_back(i);
            } else {
                R.push_back(i);
            }
            ask(j);
        }
        L = solve(L);
        R = solve(R);
        L.push_back(j);
        L.insert(L.end(), R.begin(), R.end());
        return L;
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> I(n);
        iota(I.begin(), I.end(), 0);
        vector<int> J = solve(I);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[J[i]] = i + 1;
        }
        cout << "!";
        for (int i = 0; i < n; ++i) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
}
