/**
 *    author:  MaGnsi0
 *    created: 10.12.2023 14:07:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> tshirts(4, 0);
    tshirts[0] = m;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            tshirts[0] += tshirts[2];
            tshirts[1] += tshirts[3];
            tshirts[2] = tshirts[3] = 0;
        } else if (s[i] == '1') {
            if (tshirts[0]) {
                tshirts[0]--;
                tshirts[2]++;
            } else if (tshirts[1]) {
                tshirts[1]--;
                tshirts[3]++;
            } else {
                tshirts[3]++;
            }
        } else {
            if (tshirts[1]) {
                tshirts[1]--;
                tshirts[3]++;
            } else {
                tshirts[3]++;
            }
        }
    }
    cout << tshirts[1] + tshirts[3];
}
