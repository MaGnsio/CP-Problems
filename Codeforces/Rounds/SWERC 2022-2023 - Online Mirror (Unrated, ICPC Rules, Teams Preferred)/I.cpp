/**
 *    author:  MaGnsi0
 *    created: 26.02.2023 22:09:45
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 400;

vector<int> x(N), y(N);

int64_t area_(int64_t ax, int64_t ay, int64_t bx, int64_t by, int64_t cx, int64_t cy){
    long long top = ax * (by - cy) + bx * (cy - ay) + cx * (ay - by);
    return abs(top);
}

int64_t area(int i, int j, int k){
    return area_(x[i], y[i], x[j], y[j], x[k], y[k]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<bool> done(n, 0);
    if (n & 1) {
        cout << "Beatrice" << endl;
        int x;
        cin >> x;
        done[x - 1] = true;
    } else {
        cout << "Alberto" << endl;
    }
    while (true) {
        pair<int64_t, int> ans = {INT64_MAX, -1};
        for (int i = 0; i < n; ++i) {
            if (done[i]) { continue; }
            int j = (i + 1) % n, k = (i + n - 1) % n;
            while (done[j]) { j++, j %= n; }
            while (done[k]) { k--, k += n, k %= n; }
            ans = min(ans, {area(j, i, k), i});
        }
        if (ans.second == -1) { break; }
        cout << ans.second + 1 << endl;
        done[ans.second] = true;
        int x;
        cin >> x;
        done[x - 1] = true;
    }
}
