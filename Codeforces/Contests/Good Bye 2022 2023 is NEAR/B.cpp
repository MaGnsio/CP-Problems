/**
 *    author:  MaGnsi0
 *    created: 30.12.2022 16:47:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            s.insert(i);
        }
        while (!s.empty()) {
            for (int i = 0; i < k - 1; ++i) {
                if (s.empty()) {
                    break;
                }
                a.push_back(*s.rbegin());
                s.erase(*s.rbegin());
            }
            if (!s.empty()) {
                a.push_back(*s.begin());
                s.erase(s.begin());
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
