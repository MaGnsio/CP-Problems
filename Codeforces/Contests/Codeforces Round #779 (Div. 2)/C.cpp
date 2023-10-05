/**
 *    author:  MaGnsi0
 *    created: 27.03.2022 16:27:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (count(a.begin(), a.end(), 1) != 1) {
            cout << "NO\n";
            continue;
        }
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                vector<int> b;
                for (int j = i; j < n; ++j) {
                    b.push_back(a[j]);
                }
                for (int j = 0; j < i; ++j) {
                    b.push_back(a[j]);
                }
                a = b;
                break;
            }
        }
        bool ok = true;
        vector<int> lastwith(n + 1, -1);
        lastwith[1] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] - 1 > a[i - 1]) {
                ok = false;
            }
            if (lastwith[a[i] - 1] == -1) {
                ok = false;
            }
            lastwith[a[i]] = i;
        }
        cout << (ok ? "YES" : "NO") << "\n";
   }
}
