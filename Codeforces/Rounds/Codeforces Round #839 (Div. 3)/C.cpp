/**
 *    author:  MaGnsi0
 *    created: 31.01.2023 21:20:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int k, n;
        cin >> k >> n;
        vector<int> a(1, 1);
        vector<bool> done(n + 1, false);
        done[1] = true;
        for (int i = 1; i < k; ++i) {
            int x = a[i - 1] + i;
            if (x > n || done[x] || n - x < k - i - 1) { break; }
            a.push_back(x);
            done[x] = true;
        }
        for (int i = 1; i <= n; ++i) {
            if (a.size() == k) { break; }
            if (done[i] || i < a.back()) { continue; }
            a.push_back(i);
        }
        for (int i = 0; i < k; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
