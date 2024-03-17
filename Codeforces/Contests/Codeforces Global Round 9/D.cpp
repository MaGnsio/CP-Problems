/**
 *    author:  MaGnsi0
 *    created: 23.01.2024 18:55:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), operations;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        function<int()> calc_mex = [&]() {
            int mex = 0;
            set<int> s(a.begin(), a.end());
            while (s.count(mex)) { mex++; }
            return mex;
        };
        while (true) {
            int mex = calc_mex();
            if (mex >= n) {
                for (int i = 0; i < n; ++i) {
                    if (a[i] == i) { continue; }
                    operations.push_back(i + 1);
                    a[i] = mex;
                    break;
                }
            } else {
                operations.push_back(mex + 1);
                a[mex] = mex;
            }
            bool bad = false;
            for (int i = 0; i < n; ++i) {
                bad |= a[i] != i;
            }
            if (!bad) { break; }
        }
        cout << (int)operations.size() << "\n";
        for (int x : operations) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
