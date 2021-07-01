//https://codeforces.com/gym/102757/problem/C
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    double x, y, maxD = 1e-9;
    cin >> x >> y;
    for (int i = 0; i < N; ++i) {
        double a, b;
        cin >> a >> b;
        maxD = max(maxD, sqrt((a - x) * (a - x) + (b - y) * (b - y)));
    }
    cout << fixed << setprecision(14) << maxD;
}
