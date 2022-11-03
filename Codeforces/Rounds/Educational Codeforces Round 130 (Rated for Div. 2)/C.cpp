/**
 *    author:  MaGnsi0
 *    created: 13.06.2022 09:35:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        if (count(s.begin(), s.end(), 'a') != count(t.begin(), t.end(), 'a')) {
            cout << "NO\n";
            continue;
        }
        if (count(s.begin(), s.end(), 'b') != count(t.begin(), t.end(), 'b')) {
            cout << "NO\n";
            continue;
        }
        stack<int> a;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a' && t[i] == 'a') {
                continue;
            } else if (s[i] == 'a' && t[i] != 'a') {
                a.push(i);
            } else if (s[i] != 'a' && t[i] == 'a') {
                if (s[i] == 'b' && !a.empty()) {
                    swap(s[i], s[a.top()]);
                } else {
                    break;
                }
                a.pop();
            } else if (s[i] != 'b' && !a.empty()) {
                break;
            }
        }
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        stack<int> c;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'c' && t[i] == 'c') {
                continue;
            } else if (s[i] == 'c' && t[i] != 'c') {
                c.push(i);
            } else if (s[i] != 'c' && t[i] == 'c') {
                if (s[i] == 'b' && !c.empty()) {
                    swap(s[i], s[c.top()]);
                } else {
                    break;
                }
                c.pop();
            } else if (s[i] != 'b' && !c.empty()) {
                break;
            }
        }
        cout << (s == t ? "YES" : "NO") << "\n";
    }
}
