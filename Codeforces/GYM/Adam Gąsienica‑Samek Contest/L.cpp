/**
 *    author:  MaGnsi0
 *    created: 02.09.2023 11:14:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    function<int(int, int)> ask = [&](int a, int b) {
        cout << "? " << a << " " << b << endl;
        int x; cin >> x;
        return x;
    };
    vector<int> ans(n);
    for (int i = 0; i < n - 1; ++i) {
        ans[i] = ask(i + 1, n);
    }
    map<int, int> F;
    for (int i = 0; i < n - 1; ++i) {
        F[ans[i]]++;
    }
    int maxF = 0, cntF = 0;
    for (auto [x, y] : F) {
        maxF = max(maxF, y);
    }
    for (auto [x, y] : F) {
        cntF += y == maxF;
    }
    if (cntF == 1) {
        int t;
        for (int i = 0; i < n - 1; ++i) {
            if (F[ans[i]] == maxF) {
                t = i;
            }
        }
        int x1 = ask(t + 1, 1);
        int x2 = ask(n, 1);
        if (x1 == x2) {
            ans[n - 1] = ans[t];
        } else {
            ans[n - 1] = -1;
        }
        int k = 0;
        vector<int> liars;
        for (int i = 0; i < n; ++i) {
            if (ans[i] != ans[t]) {
                liars.push_back(i + 1);
                k++;
            }
        }
        cout << "! " << k;
        for (int i = 0; i < k; ++i) {
            cout << " " << liars[i];
        }
        cout << endl;
    } else { //n is truth teller
        assert(cntF == 2 && (int)F.size() == 2);
        int t1, t2;
        for (int i = 0; i < n - 1; ++i) {
            if (ans[i] == F.begin() -> first) {
                t1 = i;
            } else {
                assert(ans[i] == F.rbegin() -> first);
                t2 = i;
            }
        }
        int x1 = ask(n, t1 + 1);
        int x2 = ask(t2 + 1, t1 + 1);
        int k = 0;
        vector<int> liars;
        if (x1 == x2) {
            ans[n - 1] = ans[t2];
            for (int i = 0; i < n; ++i) {
                if (ans[i] != ans[t2]) {
                    liars.push_back(i + 1);
                    k++;
                }
            }
        } else {
            ans[n - 1] = ans[t1];
            for (int i = 0; i < n; ++i) {
                if (ans[i] != ans[t1]) {
                    liars.push_back(i + 1);
                    k++;
                }
            }
        }
        cout << "! " << k;
        for (int i = 0; i < k; ++i) {
            cout << " " << liars[i];
        }
        cout << endl;
    }
}
