/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 20:02:47
**/
#include <bits/stdc++.h>

using namespace std;

int F(string s) {
    int n = (int)s.size();
    set<string> S;
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i + l - 1 < n; ++i) {
            S.insert(s.substr(i, l));
        }
    }
    return (int)S.size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string W[3] = {"OOOOOOO", "XOOOOOO", "XOXOOOO"};
    for (int i = 0; i < n; ++i) {
        cout << W[i] << endl;
    }
    int Q; cin >> Q;
    while (Q--) {
        int score; cin >> score;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (F(W[i] + W[j]) == score) {
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
    }
}
