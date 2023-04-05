/**
 *    author:  MaGnsi0
 *    created: 01.12.2022 11:09:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    vector<int64_t> Calories(1, 0);
    string in;
    while (getline(cin, in)) {
        if (in == "") {
            Calories.push_back(0);
        } else {
            Calories.back() += stoll(in);
        }
    }
    sort(Calories.rbegin(), Calories.rend());
    cout << Calories[0];
}
