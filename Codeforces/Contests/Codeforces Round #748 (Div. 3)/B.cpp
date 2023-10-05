/**
 *    author:  MaGnsi0
 *    created: 13.10.2021 16:27:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string n;
        cin >> n;
        int res = (int)n.size() - 1;
        for (int i = 0; i < (int)n.size(); ++i) {
            for (int j = i + 1; j < n.size(); ++j) {
                string s = "";
                s += n[i], s += n[j];
                if (s == "25" || s == "50" || s == "75" || s == "00") {
                    int cnt = 0;
                    for (int k = 0; k < i; ++k) {
                        if (n[k] != '0') {
                            break;
                        }
                        cnt++;
                    }
                    if (cnt == i && s == "00") {
                        continue;
                    }
                    res = min(res, cnt + (j - i - 1) + ((int)n.size() - j - 1));
                }
            }
        }
        cout << res << "\n";
    }
}
