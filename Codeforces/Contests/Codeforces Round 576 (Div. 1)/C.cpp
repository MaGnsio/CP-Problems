/**
 *    author:  MaGnsi0
 *    created: 12.01.2025 16:01:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> a(m), b(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i]; a[i]--;
            cin >> b[i]; b[i]--;
        }
        vector<int> matching;
        vector<bool> done(3 * n, false);
        for (int i = 0; i < m; ++i) {
            if (!done[a[i]] && !done[b[i]]) {
                matching.push_back(i + 1);
                done[a[i]] = done[b[i]] = true;
            }
        }
        if (count(done.begin(), done.end(), false) >= n) {
            cout << "IndSet\n";
            for (int i = 0, j = 0; i < 3 * n && j < n; ++i) {
                if (!done[i]) {
                    cout << i + 1 << " ";
                    j++;
                }
            }
        } else {
            cout << "Matching\n";
            for (int i = 0; i < n; ++i) {
                cout << matching[i] << " ";
            }
        }
        cout << "\n";
    }
}
