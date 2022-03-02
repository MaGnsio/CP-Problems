/**
 *    author:  MaGnsi0
 *    created: 11.02.2022 03:55:12
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int L, H, R, farthest = 0;
    vector<int> height(N, 0);
    while (cin >> L >> H >> R) {
        farthest = max(farthest, R);
        for (int i = L; i < R; ++i) {
            height[i] = max(height[i], H);
        }
    }
    int last_height = height[1];
    cout << "1 " << height[1];
    for (int i = 2; i < farthest; ++i) {
        if (height[i] != last_height) {
            cout << " " << i << " " << height[i];
            last_height = height[i];
        }
    }
    cout << " " << farthest << " 0\n";
}
