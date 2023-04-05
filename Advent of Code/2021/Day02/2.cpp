/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 02:15:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input2.txt", "r", stdin);
    int64_t aim = 0, horizontal = 0, depth = 0, amount;
    string command;
    while (cin >> command >> amount) {
        if (command == "up") {
            aim -= amount;
        } else if (command == "down") {
            aim += amount;
        } else {
            horizontal += amount;
            depth += (amount * aim);
        }
    }
    cout << horizontal * depth;

}
