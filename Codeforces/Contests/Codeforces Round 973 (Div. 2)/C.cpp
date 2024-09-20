/**
 *    author:  MaGnsi0
 *    created: 20.09.2024 17:46:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s = "1";
        function<int()> ask = [&]() {
            cout << "? " << s << endl;
            int x; cin >> x; return x;
        };
        if (ask() == 0) {
            s = string(n, '0');
            cout << "! " << s << endl;
            continue;
        }
        bool l = false, r = false;
        while ((int)s.size() != n) {
            if (!r) {
                s = s + "0";
                if (ask() == 1) { continue; }
                s.pop_back(); s = s + "1";
                if (ask() == 1) { continue; }
                s.pop_back();
                r = true;
            }
            if (!l) {
                s = "0" + s;
                if (ask() == 1) { continue; }
                s = s.substr(1); s = "1" + s;
                if (ask() == 1) { continue; }
                s = s.substr(1);
                l = true;
            }
        }
        cout << "! " << s << endl;
    }
}
