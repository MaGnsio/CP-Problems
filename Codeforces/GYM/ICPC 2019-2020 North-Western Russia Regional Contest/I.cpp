/**
 *    author:  MaGnsi0
 *    created: 04.10.2023 22:14:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int minX = INT_MAX, minY = INT_MAX;
    int maxX = INT_MIN, maxY = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int x, y, h;
        cin >> x >> y >> h;
        minX = min(minX, x - h);
        minY = min(minY, y - h);
        maxX = max(maxX, x + h);
        maxY = max(maxY, y + h);
    }
    int cX = (maxX + minX) / 2;
    int cY = (maxY + minY) / 2;
    int h = max(maxX - minX + 1, maxY - minY + 1) / 2;
    cout << cX << " " << cY << " " << h;
}
