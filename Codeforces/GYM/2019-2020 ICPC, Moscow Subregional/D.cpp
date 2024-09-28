/**
 *    author:  MaGnsi0
 *    created: 28.09.2024 19:41:03
**/
#include <bits/stdc++.h>

using namespace std;

const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y) {
    return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

tuple<int, int, int, int> next_day(int y, int m, int d, int wd) {
    if (d + 1 <= months[m] + ((m == 2) && is_leap(y))) {
        return make_tuple(y, m, d + 1, (wd == 7 ? 1 : wd + 1));
    }
    if (m != 12) {
        return make_tuple(y, m + 1, 1, (wd == 7 ? 1 : wd + 1));
    }
    return make_tuple(y + 1, 1, 1, (wd == 7 ? 1 : wd + 1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int y = 1900, m = 1, d = 1, wd = 2, w = 1;
    vector day_pos(202, vector(13, vector<pair<int, int>>(32, {-1, -1})));
    while (!(y == 2101 && m == 1 && d == 1)) {
        day_pos[y - 1900][m][d] = {w, wd};
        auto [ny, nm, nd, nwd] = next_day(y, m, d, wd);
        if (nm != m) { w = 1; }
        else { w += nwd == 1; }
        y = ny, m = nm, d = nd, wd = nwd;
    }
    int Q; cin >> Q;
    while (Q--) {
        int d1; cin >> d1;
        int m1; cin >> m1;
        int y1; cin >> y1;
        int d2; cin >> d2;
        int m2; cin >> m2;
        int y2; cin >> y2;
        if (day_pos[y2 - 1900][m2][d2] == make_pair(-1, -1)) {
            cout << "Unspecified Server Error\n";
            continue;
        }
        char y_dir = (y1 < y2 ? 'd' : 'u');
        int y_diff = abs(y1 - y2);
        char m_dir = (m1 < m2 ? 'r' : 'l');
        int m_diff = abs(m1 - m2);
        if (y_diff) {
            cout << y_dir << ":" << y_diff << " ";
        }
        if (m_diff) {
            cout << m_dir << ":" << m_diff << " ";
        }
        auto [w, wd] = day_pos[y2 - 1900][m2][d2];
        cout << "[" << w << "][" << wd << "]\n";
    }
}
