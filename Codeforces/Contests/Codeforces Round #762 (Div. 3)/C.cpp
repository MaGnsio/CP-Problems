/**
 *    author:  MaGnsi0
 *    created: 05.01.2022 21:24:43
**/
#include <bits/stdc++.h>

using namespace std;

string solve(string a, string b, string c) {
    if (a.empty() && b.empty() && c.empty()) {
        return "";
    }
    if (a.empty() || b.empty() || c.empty()) {
        return "-1";
    }
    if (c.size() >= 2) {
        int x = a[0] - '0';
        int z = stoi(c.substr(0, 2));
        if (z >= 10 && z - x >= 0 && z - x <= 9) {
            string res = solve(a.substr(1), b.substr(1), c.substr(2));
            if (res[0] != '-') {
                return to_string(z - x) + res;
            }
        }
    }
    int x = a[0] - '0';
    int z = c[0] - '0';
    if (z - x >= 0 && z - x <= 9) {
        string res = solve(a.substr(1), b.substr(1), c.substr(1));
        if (res[0] != '-') {
            return to_string(z - x) + res;
        }
    }
    return "-1";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string a, c;
        cin >> a >> c;
        string b = "-1";
        for (int i = (int)a.size(); i <= 18; ++i) {
            string x = a;
            while ((int)x.size() < i) {
                x.insert(x.begin(), '0');
            }
            string y(i, '0');
            string res = solve(x, y, c);
            if (res != "-1") {
                b = res;
                break;
            }
        }
        while ((int)b.size() > 1 && b[0] == '0') {
            b.erase(b.begin());
        }
        cout << b << "\n";
    }
}
