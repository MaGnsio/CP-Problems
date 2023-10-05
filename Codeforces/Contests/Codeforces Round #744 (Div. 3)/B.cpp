/**
 *    author:  MaGnsi0
 *    created: 28/09/2021 16:19:15
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<int> f = v;
        sort(f.begin(), f.end());
        vector<int> a, b, c;
        for (int i = 0; i < n; ++i) {
            if (f[i] == v[i]) {
                continue;
            }
            for (int j = i + 1; j < n; ++j) {
                if (f[i] != v[j]) {
                    continue;
                }
                vector<int> new_v = v;
                new_v[i] = v[j];
                for (int k = i + 1; k <= j; ++k) {
                    new_v[k] = v[k - 1];
                }
                v = new_v;
                a.push_back(i + 1);
                b.push_back(j + 1);
                c.push_back(j - i);
            }
        }
        cout << (int)a.size() << "\n";
        for (int i = 0; i < (int)a.size(); ++i) {
            cout << a[i] << " " << b[i] << " " << c[i] << "\n";
        }
    }
}
