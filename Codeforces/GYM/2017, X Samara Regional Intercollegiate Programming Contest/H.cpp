#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n, 0), c(n, 0);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < (int)a[i].size(); ++j) {
            if (a[i][j] == '(') {
                cnt++;
            } else {
                if (cnt) {
                    cnt--;
                } else {
                    b[i]++;
                }
            }
        }
        c[i] = cnt;
    }
    vector<tuple<int, int, int>> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = make_tuple(b[i], c[i], i);
    }
    sort(d.begin(), d.end(), [&](tuple<int, int, int> x, tuple<int, int, int> y) {
            int a1 = get<0>(x), b1 = get<1>(x);
            int a2 = get<0>(y), b2 = get<1>(y);
            if (b1 >= a1 && b2 >= a2) {
                return a1 < a2;
            } else if (b1 >= a1) {
                return true;
            } else if (b2 >= a2) {
                return false;
            } else {
                return b1 > b2;
            }
        });
    int now = 0;
    for (int i = 0; i < n; ++i) {
        string s = a[get<2>(d[i])];
        for (int j = 0; j < (int)s.size(); ++j) {
            if (s[j] == '(') {
                now++;
            } else {
                if (now > 0) {
                    now--;
                } else {
                    cout << "impossible";
                    return 0;
                }
            }
        }
    }
    if (now != 0) {
        cout << "impossible";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << get<2>(d[i]) + 1 << "\n";
    }
}
