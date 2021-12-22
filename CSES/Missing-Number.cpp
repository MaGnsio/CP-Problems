/**
 *    author:  MaGnsi0
 *    created: 11.11.2021 17:36:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    unordered_set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(i);
    }
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        s.erase(x);
    }
    cout << *s.begin();
}
