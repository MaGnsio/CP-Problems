/**
 *    author:  MaGnsi0
 *    created: 11.11.2021 16:00:52
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
        char mini = *min_element(s.begin(), s.end()); 
        cout << mini << " ";
        for (int i = 0, k = 1; i < (int)s.size(); ++i) {
            if (s[i] == mini && k) {
                k = 0;
                continue;
            }
            cout << s[i];
        }
        cout << "\n";
    }
}
