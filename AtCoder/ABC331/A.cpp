/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 14:00:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M; cin >> M;
    int D; cin >> D;
    int y; cin >> y;
    int m; cin >> m;
    int d; cin >> d;
    if (d < D) {
        d++;
    } else {
        d = 1;
        if (m < M) {
            m++;
        } else {
            m = 1;
            y++;
        }
    }
    cout << y << " " << m << " " << d;
}
