/**
 *    author:  MaGnsi0
 *    created: 29/09/2021 19:26:52
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 33, M = 102 * N;

int n;
string s;
int a[N];
char b[N];
bool dp[N][2 * M][N];
set<int> _s;

void init() {
    n = 0;
    memset(dp, 0, sizeof dp);
    _s.clear();
}

void get_input() {
    stringstream __cin(s);
    __cin >> a[0];
    b[0] = '+';
    while (__cin >> b[++n] >> a[n]) {
        if (b[n] == '-') {
            a[n] *= -1;
        }
    }
}

void solve(int i = 0, int j = 0, int k = 0) {
    if (i >= n) {
        _s.insert(j);
        return;
    }
    if (dp[i][M + j][k]) {
        return;
    }
    dp[i][M + j][k] = true;
    for (int x = 0; x <= k; ++x) {
        if (b[i] == '-') {
            solve(i + 1, j + (x & 1 ? -a[i] : a[i]), x + 1);
        }
        solve(i + 1, j + (x & 1 ? -a[i] : a[i]), x);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (getline(cin, s)) {
        init();
        get_input();
        solve();
        cout << (int)_s.size() << "\n";
    }
}
