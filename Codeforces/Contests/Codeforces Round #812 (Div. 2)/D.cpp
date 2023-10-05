/**
 *    author:  MaGnsi0
 *    created: 06.08.2022 16:34:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(1 << n);
        iota(a.begin(), a.end(), 0);
        function<int(int, int)> ask = [](int a, int b) {
            cout << "? " << a + 1 << " " << b + 1 << endl;
            int x;
            cin >> x;
            return x;
        };
        while ((int)a.size() > 2) {
            vector<int> na;
            for (int j = 0; j < (int)a.size(); j += 4) {
                int x = ask(a[j], a[j + 2]);
                if (x == 0) {
                    int y = ask(a[j + 1], a[j + 3]);
                    if (y == 1) {
                        na.push_back(a[j + 1]);
                    } else {
                        na.push_back(a[j + 3]);
                    }
                } else if (x == 1) {
                    int y = ask(a[j], a[j + 3]);
                    if (y == 1) {
                        na.push_back(a[j]);
                    } else {
                        na.push_back(a[j + 3]);
                    }
                } else {
                    int y = ask(a[j + 1], a[j + 2]);
                    if (y == 1) {
                        na.push_back(a[j + 1]);
                    } else {
                        na.push_back(a[j + 2]);
                    }
                }
            }
            a = na;
        }
        if ((int)a.size() == 1) {
            cout << "! " << a[0] + 1 << endl;
        } else {
            int x = ask(a[0], a[1]);
            cout << "! " << (x == 1 ? a[0] + 1 : a[1] + 1) << endl;
        }
    }
}
