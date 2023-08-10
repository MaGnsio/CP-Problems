/**
 *    author:  MaGnsi0
 *    created: 30.03.2023 22:20:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        function<bool(string, string)> F = [&](string s, string t) {
            int n = (int)s.size(), m = (int)t.size();
            int i = 0, j = 0;
            while (i < n && j < m) {
                if (s[i] == t[j]) {
                    i++, j++;
                    continue;
                }
                if (s[i] > t[j]) {
                    return false;
                }
                int k = i, size = 0;
                string x = "";
                while (k < n && x != t.substr(j, 1)) {
                    x += s[k];
                    size++;
                    while (size >= 2 && x[size - 1] != 'z' && x[size - 1] == x[size - 2]) {
                        char c = x[size - 1]; c++;
                        x.pop_back(), x.pop_back(), x += c, size--;
                    }
                    k++;
                }
                if (x != t.substr(j, 1)) {
                    return false;
                }
                i = k, j++;
            }
            return (i == n && j == m);
        };
        cout << (F(s, t) ? "YES" : "NO") << "\n";
    }
}
