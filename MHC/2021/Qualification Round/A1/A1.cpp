/**
 *    author:  MaGnsi0
 *    created: 30/08/2021 14:56:47
**/
#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> f(26, 0);
        for (int i = 0; i < n; ++i) {
            f[s[i] - 'A']++;
        }
        char v = 'A', c = 'B';
        for (int i = 0; i < 26; ++i) {
            if (is_vowel(char('A' + i)) && f[i] > f[v - 'A']) {
                v = char('A' + i);
            } else if (!is_vowel(char('A' + i)) && f[i] > f[c - 'A']) {
                c = char('A' + i);
            }
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != v) {
                if (is_vowel(s[i])) {
                    cnt1 += 2;
                } else {
                    cnt1 += 1;
                }
            }
            if (s[i] != c) {
                if (!is_vowel(s[i])) {
                    cnt2 += 2;
                } else {
                    cnt2 += 1;
                }
            }
        }
        cout << "Case #" << t << ": " << min(cnt1, cnt2) << "\n";
    }
}
