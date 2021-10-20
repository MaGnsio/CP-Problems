/**
 *    author:  MaGnsi0
 *    created: 16/08/2021 19:13:27
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (s[j] == '?' && j < n) {
                j++;
            }
            if (!i) {
                for (int k = j - 1; k >= i; --k) {
                    s[k] = (s[k + 1] == 'R' ? 'B' : 'R');
                }
            } else {
                for (int k = i; k < j; ++k) {
                    s[k] = (s[k - 1] == 'R' ? 'B' : 'R');
                }
            }
            i = j;
        }
        cout << s << "\n";
    }
}
