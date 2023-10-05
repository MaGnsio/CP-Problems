/**
 *    author:  MaGnsi0
 *    created: 18/08/2021 16:27:55
**/
#include <bits/stdc++.h>
using namespace std;

string f1(string n) {
    string res(n.length(), '9');
    for (char c = '8'; c >= '0'; c--) {
        string t(n.length(), c);
        if (t >= n) {
            res = t;
        }
    }
    return res;
}

string f2(string n) {
    string res = f1(n);
    for (char a = '0'; a <= '9'; a++) {
        for (char b = a + 1; b <= '9'; b++) {
            bool ok = true;
            for (int i = 0; i < n.size(); i++) {
                if (b > n[i]) {
                    string t = n;
                    t[i] = (a > t[i] ? a : b);
                    for (int j = i + 1; j < n.size(); j++) {
                        t[j] = a;
                    }
                    if (t < res) {
                        res = t;
                    }
                }
                if (n[i] != a && n[i] != b) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return n;
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int k;
        string n;
        cin >> n >> k;
        cout << (k == 1 ? f1(n) : f2(n)) << "\n";
    }
}
