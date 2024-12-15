/**
 *    author:  MaGnsi0
 *    created: 15.12.2024 17:42:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        set<int> zeros, ones, twos;
        for (int i = 0; i < n; ++i) {
            zeros.insert(i);
        }
        for (int i = 0; i < n; ++i) {
            if (zeros.count(a[i])) {
                assert(twos.empty());
                zeros.erase(a[i]);
                ones.insert(a[i]);
                cout << a[i] + 1 << " ";
            } else if (ones.count(a[i])) {
                if (!twos.empty() || zeros.empty()) {
                    ones.erase(a[i]);
                    twos.insert(a[i]);
                    cout << a[i] + 1 << " ";
                } else {
                    int x = *zeros.begin();
                    zeros.erase(x);
                    ones.insert(x);
                    cout << x + 1 << " ";
                }
            } else {
                if (zeros.empty()) {
                    int x = *ones.begin();
                    ones.erase(x);
                    zeros.insert(x);
                    cout << x + 1 << " ";
                } else {
                    int x = *zeros.begin();
                    zeros.erase(x);
                    ones.insert(x);
                    cout << x + 1 << " ";
                }
            }
        }
        cout << "\n";
    }
}
