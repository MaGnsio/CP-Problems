/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 17:39:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    map<int, vector<int>> xpos, xneg, ypos, yneg;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        xpos[a].push_back(b);
        xneg[a].push_back(-b);
        ypos[b].push_back(a);
        yneg[b].push_back(-a);
    }
    for (auto& [_, a] : xpos) {
        sort(a.begin(), a.end());
    }
    for (auto& [_, a] : xneg) {
        sort(a.begin(), a.end());
    }
    for (auto& [_, a] : ypos) {
        sort(a.begin(), a.end());
    }
    for (auto& [_, a] : yneg) {
        sort(a.begin(), a.end());
    }
    int Q;
    cin >> Q;
    while (Q--) {
        char d;
        cin >> d;
        if (d == 'U') {
            if (xpos.count(x) == 0) {
                cout << x << " " << y << "\n";
                continue;
            }
            auto it = upper_bound(xpos[x].begin(), xpos[x].end(), y);
            if (it == xpos[x].end()) {
                cout << x << " " << y << "\n";
                continue;
            }
            y = *it;
        } else if (d == 'D') {
            if (xneg.count(x) == 0) {
                cout << x << " " << y << "\n";
                continue;
            }
            auto it = upper_bound(xneg[x].begin(), xneg[x].end(), -y);
            if (it == xneg[x].end()) {
                cout << x << " " << y << "\n";
                continue;
            }
            y = -(*it);
        } else if (d == 'R') {
            if (ypos.count(y) == 0) {
                cout << x << " " << y << "\n";
                continue;
            }
            auto it = upper_bound(ypos[y].begin(), ypos[y].end(), x);
            if (it == ypos[y].end()) {
                cout << x << " " << y << "\n";
                continue;
            }
            x = *it;
        } else {
            if (yneg.count(y) == 0) {
                cout << x << " " << y << "\n";
                continue;
            }
            auto it = upper_bound(yneg[y].begin(), yneg[y].end(), -x);
            if (it == yneg[y].end()) {
                cout << x << " " << y << "\n";
                continue;
            }
            x = -(*it);
        }
        cout << x << " " << y << "\n";
    }
}
