/**
 *    author:  MaGnsi0
 *    created: 21.12.2024 20:25:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    string s; cin >> s; s = "#" + s;
    vector<int> prex(n + 2), prey(n + 2);
    vector<int> sufx(n + 2), sufy(n + 2);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'R') {
            prex[i]++, sufx[i]++;
        } else if (s[i] == 'L') {
            prex[i]--, sufx[i]--;
        } else if (s[i] == 'U') {
            prey[i]++, sufy[i]++;
        } else {
            prey[i]--, sufy[i]--;
        }
    }
    for (int i = 1; i <= n + 1; ++i) {
        prex[i] += prex[i - 1];
        prey[i] += prey[i - 1];
    }
    for (int i = n; i >= 0; --i) {
        sufx[i] += sufx[i + 1];
        sufy[i] += sufy[i + 1];
    }
    map<pair<int, int>, int> early, late;
    for (int i = n; i >= 0; --i) {
        int x = prex[i], y = prey[i];
        early[{x, y}] = i;
    }
    for (int i = 0; i <= n; ++i) {
        int x = prex[i], y = prey[i];
        late[{x, y}] = i;
    }
    map<pair<int, int>, set<int>> S;
    for (int i = 1; i <= n; ++i) {
        int x = sufx[i], y = sufy[i];
        S[{x, y}].insert(i);
    }
    while (Q--) {
        int x_q; cin >> x_q;
        int y_q; cin >> y_q;
        int l; cin >> l;
        int r; cin >> r;
        if (early.count({x_q, y_q}) && (early[{x_q, y_q}] < l || late[{x_q, y_q}] > r)) {
            cout << "YES\n";
            continue;
        }
        int x = prex[l - 1], y = prey[l - 1];
        int X = x_q + sufx[r + 1] - x;
        int Y = y_q + sufy[r + 1] - y;
        auto it = S[{X, Y}].lower_bound(l);
        bool ok = it != S[{X, Y}].end() && *it <= r;
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
