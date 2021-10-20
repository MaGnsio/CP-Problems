/**
 *    author:  MaGnsi0
 *    created: 18/09/2021 13:55:10
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    string s;
    cin >> s >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [=](string a, string b) {
            char x = '.', y;
            for (int i = 0; i < min(a.size(), b.size()); ++i) {
                if (a[i] != b[i]) {
                    x = a[i];
                    y = b[i];
                    break;
                }
            }
            if (x == '.') {
                return (a.size() <= b.size());
            }
            int idx1, idx2;
            for (int i = 0; i < 26; ++i) {
                if (s[i] == x) {
                    idx1 = i;
                }
                if (s[i] == y) {
                    idx2 = i;
                }
            }
            return (idx1 < idx2);
       });
    for (int i = 0; i < n; ++i) {
        cout << v[i] << "\n";
    }
}
