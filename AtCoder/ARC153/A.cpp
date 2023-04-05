/**
 *    author:  MaGnsi0
 *    created: 14.01.2023 14:01:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> S;
    function<void(int, vector<int>)> generate = [&](int j, vector<int> curS) {
        if (j == 10) {
            S.push_back(curS);
            return;
        }
        if (j == 1) {
            for (int i = 1; i <= 9; ++i) {
                curS.push_back(i);
                generate(j + 1, curS);
                curS.pop_back();
            }
        }
        if (j == 3 || j == 4 || j == 5 || j == 7 || j == 8) {
            for (int i = 0; i <= 9; ++i) {
                curS.push_back(i);
                generate(j + 1, curS);
                curS.pop_back();
            }
        }
        if (j == 2) {
            curS.push_back(curS[0]);
            generate(j + 1, curS);
            curS.pop_back();
        }
        if (j == 6) {
            curS.push_back(curS[4]);
            generate(j + 1, curS);
            curS.pop_back();
        }
        if (j == 9) {
            curS.push_back(curS[6]);
            generate(j + 1, curS);
            curS.pop_back();
        }
    };
    generate(1, vector<int>());
    sort(S.begin(), S.end());
    int n;
    cin >> n;
    for (int i = 0; i < 9; ++i) {
        cout << S[n - 1][i];
    }
}
