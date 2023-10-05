/**
 *    author:  MaGnsi0
 *    created: 03.01.2023 16:38:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int cntR = count(s.begin(), s.end(), 'R'); 
        int cntL = count(s.begin(), s.end(), 'L');
        if (cntR == n || cntL == n) {
            cout << -1 << "\n";
            continue;
        }
        int allL = 0;
        for (int i = 0; i < cntL; ++i) {
            allL += s[i] == 'L';
        }
        cout << (allL == cntL ? cntL : 0) << "\n";
    }
}
