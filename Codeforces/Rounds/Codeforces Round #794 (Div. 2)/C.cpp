/**
 *    author:  MaGnsi0
 *    created: 25.05.2022 19:34:25
**/
#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> a) {
    int n = (int)a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] > a[(i + 1) % n] && a[i] > a[(i - 1 + n) % n]) {
            continue;
        }
        if (a[i] < a[(i + 1) % n] && a[i] < a[(i - 1 + n) % n]) {
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int l = 0, r = (n + 1) / 2;
        vector<int> b;
        while (b.size() != n) {
            b.push_back(a[l++]);
            if (b.size() == n) {
                break;
            }
            b.push_back(a[r++]);
        }
        if (check(b)) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << b[i] << " ";
            }
            cout << "\n";
            continue;
        }
        b.clear();
        l = 0, r = (n / 2);
        while (b.size() != n) {
            b.push_back(a[r++]);
            if (b.size() == n) {
                break;
            }
            b.push_back(a[l++]);
        }
        if (check(b)) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << b[i] << " ";
            }
            cout << "\n";
            continue;
        }
        cout << "NO\n";
    }
}
