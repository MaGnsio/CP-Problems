/**
 *    author:  MaGnsi0
 *    created: 11/09/2021 19:16:43
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    freopen("weak_typing_chapter_1_input.txt", "r", stdin);
    freopen("weak_typing_chapter_1_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n;
        string s;
        cin >> n >> s;
        int res = 0, i = 0;
        char cur;
        for (i = 0; i < n; ++i) {
            if (s[i] != 'F') {
                cur = s[i];
                break;
            }
        }
        for (i = i + 1; i < n; ++i) {
            if (cur == 'O' && s[i] == 'X') {
                cur = s[i];
                res++;
            }
            if (cur == 'X' && s[i] == 'O') {
                cur = s[i];
                res++;
            }
        }
        cout << "Case #" << tc << ": " << res << "\n";
    }
}
