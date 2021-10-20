/**
 *    author:  MaGnsi0
 *    created: 06/10/2021 00:03:04
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, x;
    cin >> n >> x;
    vector<int> f(N, 0);
    for (int i = 0; i < n; ++i) {
        int s, d;
        cin >> s >> d;
        f[s]++, f[s + d + 1]--;
    }
    for (int i = 1; i < N; ++i) {
        f[i] += f[i - 1];
    }
    int m, c = INT_MAX;
    auto solve = [=](int i) {
        int cnt = 0;
        for (int j = i; j < N; j += x) {
            cnt += f[j];
        }
        return cnt;
    };
    for (int i = 0; i <= 480; ++i) {
        int cnt = solve(i);
        if (cnt < c) {
            c = cnt;
            m = i;
        }
    }
    cout << m << " " << c;
}
