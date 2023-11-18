/**
 *    author:  MaGnsi0
 *    created: 28.10.2023 10:28:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unordered_map<char, int> MP;
    MP['T'] = 10, MP['J'] = 11;
    MP['Q'] = 12, MP['K'] = 13, MP['A'] = 14;
    int T; cin >> T; cin.ignore();
    while (T--) {
        string in; getline(cin, in);
        stringstream sin(in);
        char x;
        deque<int> a, b;
        while (sin >> x) {
            if ('0' <= x && x <= '9') {
                a.push_back(x - '0');
            } else {
                a.push_back(MP[x]);
            }
        }
        getline(cin, in);
        sin = stringstream(in);
        while (sin >> x) {
            if ('0' <= x && x <= '9') {
                b.push_back(x - '0');
            } else {
                b.push_back(MP[x]);
            }
        }
        int turns = 0;
        while (!a.empty() && !b.empty() && turns < 1e6) {
            int x = a.front(); a.pop_front();
            int y = b.front(); b.pop_front();
            if (x < y) {
                b.push_back(x);
            } else if (x > y) {
                a.push_back(y);
            } else {
                a.push_back(x);
                b.push_back(y);
            }
            turns++;
        }
        if (!a.empty() && !b.empty()) {
            cout << "draw\n";
            continue;
        }
        cout << "player " << (a.empty() ? 2 : 1) << "\n";
    }
}
