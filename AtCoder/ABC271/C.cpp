/**
 *    author:  MaGnsi0
 *    created: 01.10.2022 14:11:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
    }
    vector<int> b;
    while (!s.empty()) {
        b.push_back(*s.begin());
        s.erase(s.begin());
    }
    for (int i = 0; i < n; ++i) {
        if (s.count(a[i])) {
            b.push_back(a[i]);
        } else {
            s.insert(a[i]);
        }
    }
    int ans = 0, i = 0, j = n - 1;
    while (true) {
        if (i > j) { break; }
        if (b[i] == ans + 1) { ans++, i++; }
        else {
            if (j - 1 >= i) { ans++, j -= 2; }
            else { break; }
        }
    }
    cout << ans;
}
