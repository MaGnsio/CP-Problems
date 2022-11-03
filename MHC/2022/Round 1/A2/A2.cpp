/**
 *    author:  MaGnsi0
 *    created: 13.09.2022 18:06:00
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(vector<int> a) {
    int n = (int)a.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && a[i] != a[j]) {
            j = pi[j - 1];
        }
        if (a[i] == a[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("A2.in", "r", stdin);
    freopen("A2.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        cout << "Case #" << t << ": ";
        if (n == 2) {
            cout << ((a[0] == a[1]) || ((a == b) ^ (k & 1)) ? "YES" : "NO") << "\n";
            continue;
        }
        vector<int> c;
        c.insert(c.end(), b.begin(), b.end());
        c.push_back(-4);
        c.insert(c.end(), a.begin(), a.end());
        c.insert(c.end(), a.begin(), a.end());
        vector<int> d = prefix_function(c);
        bool ok = false;
        for (int i = 2 * n + 1; i < (int)d.size() - 1; ++i) {
            ok |= d[i] == n;
        }
        cout << ((k == 0 && d[2 * n] == n) || (k == 1 && ok) || (k > 1 && (d[2 * n] == n || ok)) ? "YES" : "NO") << "\n";
    }
}
