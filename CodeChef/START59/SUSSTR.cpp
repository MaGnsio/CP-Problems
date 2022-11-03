/**
 *    author:  MaGnsi0
 *    created: 05.10.2022 16:31:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t = "";
        cin >> n >> s;
        for (int cur_turn = 0, i = 0, j = n - 1; i <= j;) {
            if (cur_turn == 0) {
                if (s[i] == '0') {
                    t.insert(t.begin(), s[i]);
                } else {
                    t.push_back(s[i]);
                }
                i++;
            } else {
                if (s[j] == '1') {
                    t.insert(t.begin(), s[j]);
                } else {
                    t.push_back(s[j]);
                }
                j--;
            }
            cur_turn ^= 1;
        }
        cout << t << "\n";
    }
}
