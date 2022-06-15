/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 19:51:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int n = a + b + 2 * c + 2 * d;
        int A = count(s.begin(), s.end(), 'A');
        if (a + c + d != A) {
            cout << "NO\n";
            continue;
        }
        vector<vector<int>> segments(3);
        string cur_segment = "";
        cur_segment += s[0];
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                if ((int)cur_segment.size() > 1) {
                    int j = (cur_segment.size() & 1 ? 0 : (cur_segment[0] == 'A' ? 1 : 2));
                    segments[j].push_back((int)cur_segment.size() / 2);
                }
                cur_segment = "";
                cur_segment += s[i];
            } else {
                cur_segment += s[i];
            }
        }
        if ((int)cur_segment.size() > 1) {
            int j = (cur_segment.size() & 1 ? 0 : (cur_segment[0] == 'A' ? 1 : 2));
            segments[j].push_back((int)cur_segment.size() / 2);
        }
        for (int i = 0; i < 3; ++i) {
            sort(segments[i].begin(), segments[i].end());
        }
        for (int i = 0; i < segments[1].size(); ++i) {
            if (!c) {
                break;
            }
            if (c > segments[1][i]) {
                c -= segments[1][i];
                segments[1][i] = 0;
            } else {
                segments[1][i] -= c;
                c = 0;
            }
        }
        for (int i = 0; i < segments[2].size(); ++i) {
            if (!d) {
                break;
            }
            if (d > segments[2][i]) {
                d -= segments[2][i];
                segments[2][i] = 0;
            } else {
                segments[2][i] -= d;
                d = 0;
            }
        }
        for (int i = 0; i < segments[1].size(); ++i) {
            if (!d || segments[1][i] < 2) {
                continue;
            }
            segments[1][i]--;
            if (d > segments[1][i]) {
                d -= segments[1][i];
                segments[1][i] = 0;
            } else {
                segments[1][i] -= d;
                d = 0;
            }
        }
        for (int i = 0; i < segments[2].size(); ++i) {
            if (!c || segments[2][i] < 2) {
                continue;
            }
            segments[2][i]--;
            if (c > segments[2][i]) {
                c -= segments[2][i];
                segments[2][i] = 0;
            } else {
                segments[2][i] -= c;
                c = 0;
            }
        }
        for (int i = 0; i < segments[0].size(); ++i) {
            if (!c) {
                break;
            }
            if (c > segments[0][i]) {
                c -= segments[0][i];
                segments[0][i] = 0;
            } else {
                segments[0][i] -= c;
                c = 0;
            }
        }
        for (int i = 0; i < segments[0].size(); ++i) {
            if (!d) {
                break;
            }
            if (d > segments[0][i]) {
                d -= segments[0][i];
                segments[0][i] = 0;
            } else {
                segments[0][i] -= d;
                d = 0;
            }
        }
        cout << (!c && !d ? "YES" : "NO") << "\n";
    }
}
