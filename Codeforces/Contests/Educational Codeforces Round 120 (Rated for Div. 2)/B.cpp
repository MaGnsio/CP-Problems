/**
 *    author:  MaGnsi0
 *    created: 27.12.2021 16:26:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        set<int> liked, dis;
        for (int i = 1; i <= n; ++i) {
            liked.insert(i);
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                dis.insert(*liked.begin());
                liked.erase(*liked.begin());
            }
        }
        map<int, int> mp1, mp2;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                mp1[a[i]] = i;
            } else {
                mp2[a[i]] = i;
            }
        }
        vector<int> b(n);
        for (auto& [x, y] : mp1) {
            b[y] = *liked.begin();
            liked.erase(liked.begin());
        }
        for (auto& [x, y] : mp2) {
            b[y] = *dis.begin();
            dis.erase(dis.begin());
        }
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
}
