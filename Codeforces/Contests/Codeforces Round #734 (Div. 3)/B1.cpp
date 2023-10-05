/**
 *    author:  MaGnsi0
 *    created: 23/07/2021 16:41:45
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<int> f(26, 0);
        for (auto& c : s) {
            f[c - 'a']++;
        }
        int a = 0, b = 0;
        for (auto& x : f) {
            if (b < a) {
                swap(a, b);
            }
            if (x >= 2) {
                a++, b++;
            } else {
                a += x;
            }
        }
        cout << min(a, b) << "\n";
    }
}
