/**
 *    author:  MaGnsi0
 *    created: 21.09.2022 23:42:02
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int dx[4] = {-2, -2, 1, -1};
const int dy[4] = {1, -1, -2, -2};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> grundy(N, vector<int>(N, -1));
    function<int(vector<int>)> mex = [](vector<int> a) {
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] != i) {
                return i;
            }
        }
        return (int)a.size();
    };
    function<int(int, int)> solve = [&](int x, int y) {
        if (x < 0 || x >= N) {
            return N;
        }
        if (y < 0 || y >= N) {
            return N;
        }
        if (grundy[x][y] != -1) {
            return grundy[x][y];
        }
        vector<int> a;
        for (int i = 0; i < 4; ++i) {
            a.push_back(solve(x + dx[i], y + dy[i]));
        }
        grundy[x][y] = mex(a);
        return grundy[x][y];
    };
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            a[i] = solve(x - 1, y - 1);
        }
        int nimber = 0;
        for (int i = 0; i < k; ++i) {
            nimber ^= a[i];
        }
        cout << (nimber ? "First" : "Second") << "\n";
    }
}
