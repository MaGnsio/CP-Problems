/**
 *    author:  MaGnsi0
 *    created: 15.02.2022 05:44:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> X, Y;
        for (int i = 0; i < n; ++i) {
            char type;
            cin >> type;
            if (type == 'p') {
                int x, y;
                cin >> x >> y;
                X.push_back(x);
                Y.push_back(y);
            } else if (type == 'c') {
                int x, y, r;
                cin >> x >> y >> r;
                X.push_back(x + r);
                X.push_back(x - r);
                Y.push_back(y + r);
                Y.push_back(y - r);
            } else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                X.push_back(x1);
                X.push_back(x2);
                Y.push_back(y1);
                Y.push_back(y2);
            }
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        cout << X[0] << " " << Y[0] << " " << X.back() << " " << Y.back() << "\n";
    }
}
