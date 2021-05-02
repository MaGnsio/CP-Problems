//https://vjudge.net/contest/433801#problem/D
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int h, w, k, all = 0, cnt = 0;
    cin >> h >> w >> k;
    vector<vector<char>> v(h, vector<char> (w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> v[i][j];
            all += (v[i][j] == '#');
        }
    }
    for (int mask1 = 0; mask1 < (1LL << h); ++mask1) {
        for (int mask2 = 0; mask2 < (1LL << w); ++mask2) {
            int temp = all;
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (((1LL << i) & mask1) || ((1LL << j) & mask2)) {
                        temp -= (v[i][j] == '#');
                    }
                }
            }
            if (temp == k) {
                cnt++;
            }
        }
    }
    cout << cnt;
}

