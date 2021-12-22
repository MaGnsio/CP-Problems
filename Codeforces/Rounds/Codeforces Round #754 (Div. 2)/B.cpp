/**
 *    author:  MaGnsi0
 *    created: 12.11.2021 19:56:48
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
        string s;
        cin >> s;
        int x = count(s.begin(), s.end(), '0');
        vector<int> a, b;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0' && i >= x) {
                a.push_back(i + 1);
            }
            if (s[i] == '1' && i < x) {
                b.push_back(i + 1);
            }
        }
        assert((int)a.size() == (int)b.size());
        if (a.empty()) {
            cout << "0\n";
            continue;
        }
        cout << 1 << "\n" << 2 * (int)a.size() << " ";
        for (int i = 0; i < (int)b.size(); ++i) {
            cout << b[i] << " ";
        }
        for (int i = 0; i < (int)a.size(); ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
   }
}
