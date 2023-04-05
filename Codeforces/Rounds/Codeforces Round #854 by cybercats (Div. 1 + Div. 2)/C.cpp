/**
 *    author:  MaGnsi0
 *    created: 27.02.2023 16:57:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        string t(n, '*');
        multiset<char> s_(s.begin(), s.end()); 
        for (int i = 0; i < n; ++i) {
            if (s_.empty()) { break; }
            if (s_.size() == 1) {
                t[i] = *s_.begin();
                s_.erase(s_.begin());
            } else if (s_.size() == 2) {
                char x = *s_.begin();
                s_.erase(s_.begin());
                char y = *s_.begin();
                s_.erase(s_.begin());
                t[i] = y;
                t[n - i - 1] = x;
            } else if (s_.size() == 3) {
                char x = *s_.begin();
                s_.erase(s_.begin());
                char y = *s_.begin();
                s_.erase(s_.begin());
                char z = *s_.begin();
                s_.erase(s_.begin());
                if (x != y && y != z) {
                    t[i] = y;
                    t[n - i - 1] = x;
                    s_.insert(z);
                } else if (x == y) {
                    t[i] = x;
                    t[n - i - 1] = y;
                    s_.insert(z);
                } else if (y == z) {
                    t[i] = y;
                    t[n - i - 1] = z;
                    s_.insert(x);
                }
            } else {
                char x = *s_.begin();
                s_.erase(s_.begin());
                char y = *s_.begin();
                s_.erase(s_.begin());
                char z = *s_.begin();
                s_.erase(s_.begin());
                if (x == y) {
                    t[i] = x;
                    t[n - i - 1] = y;
                    s_.insert(z);
                } else if (y == z && s_.count(z) == s_.size()) {
                    t[i] = y;
                    t[n - i - 1] = z;
                    s_.insert(x);
                } else {
                    t[i] = y;
                    t[n - i - 1] = x;
                    s_.insert(z);
                    for (int j = i + 1; j < n; ++j) {
                        if (s_.empty()) { break; }
                        t[j] = *s_.begin();
                        s_.erase(s_.begin());
                    }
                    break;
                }
            }
        }
        cout << t << "\n";
    }
}
