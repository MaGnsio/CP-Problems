/**
 *    author:  MaGnsi0
 *    created: 21.07.2022 16:34:44
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
        int open_needed = n / 2 - count(s.begin(), s.end(), '(');
        int closed_needed = n / 2 - count(s.begin(), s.end(), ')');
        int last_open = -1, first_closed = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') {
                continue;
            }
            if (open_needed) {
                s[i] = '(';
                last_open = i;
                open_needed--;
            } else {
                s[i] = ')';
                if (first_closed == -1) {
                    first_closed = i;
                }
                closed_needed--;
            }
        }
        if (last_open == -1 || first_closed == -1) {
            cout << "YES\n";
            continue;
        }
        swap(s[last_open], s[first_closed]);
        int cur_open = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                cur_open++;
            } else {
                if (cur_open) {
                    cur_open--;
                } else {
                    cur_open = 1;
                    break;
                }
            }
        }
        cout << (cur_open ? "YES" : "NO") << "\n";
    }
}
