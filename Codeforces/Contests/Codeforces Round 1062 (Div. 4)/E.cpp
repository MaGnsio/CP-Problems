/**
 *    author:  MaGnsi0
 *    created: 28.10.2025 17:52:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int x; cin >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        function<vector<int>(int)> solve = [&](int best) {
            int remaining = k;
            vector<int> res;
            for (int i = 0; i < n; ++i) {
                int start = (i == 0 ? 0 : a[i - 1] + max(best, 1)); 
                while (start <= a[i] && a[i] - start >= best && remaining) {
                    res.push_back(start);
                    remaining--, start++;
                }
            }
            int start = a[n - 1] + max(best, 1); 
            while (start <= x && remaining) {
                res.push_back(start);
                remaining--, start++;
            }
            return res;
        };
        function<bool(int)> ok = [&](int d) {
            return int(solve(d).size()) == k;
        };
        int low = 0, high = x, best = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ok(mid)) {
                best = mid; low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        for (int x : solve(best)) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
