/**
 *    author:  MaGnsi0
 *    created: 11.07.2024 21:41:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> f(26, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        f[s[i] - 'a'][i]++;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            f[j][i] += f[j][i - 1];
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        int l; cin >> l; l--;
        int r; cin >> r; r--;
        vector<int> ft(26, 0);
        for (int i = 0; i < 26; ++i) {
            ft[i] = f[i][r] - (l ? f[i][l - 1] : 0);
        }
        int low = l;
        set<int> uft(ft.begin(), ft.end());
        map<int, int> ftl, ftr;
        for (int x : uft) {
            if (x == 0) { continue; }
            int c = (int)count(ft.begin(), ft.end(), x);
            int high = low + c * x - 1;
            ftl[x] = low, ftr[x] = high;
            low = high + 1;
        }
        assert(low == r + 1);
        bool ok = false;
        for (int i = 0; i < 26; ++i) {
            if (ft[i] == 0) { continue; }
            int low = ftl[ft[i]];
            int high = ftr[ft[i]];
            int x = f[i][high] - (low ? f[i][low - 1] : 0);
            ok |= x != ft[i];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
