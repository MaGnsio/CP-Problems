/**
 *    author:  MaGnsi0
 *    created: 19.12.2022 14:38:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n";
        cout << 1 << " " << 3 << "\n";
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> R1 = a, R2, R3;
    vector<pair<int, int>> moves;
    while (!R1.empty()) {
        if (R2.empty() || R1.back() < R2.back()) {
            moves.emplace_back(1, 2);
            R2.push_back(R1.back());
            R1.pop_back();
        } else if (R3.empty() || R1.back() < R3.back()) {
            moves.emplace_back(1, 3);
            R3.push_back(R1.back());
            R1.pop_back();
        } else {
            while (!R2.empty() && !R3.empty()) {
                if (R2.back() < R3.back()) {
                    moves.emplace_back(2, 1);
                    R1.push_back(R2.back());
                    R2.pop_back();
                } else {
                    moves.emplace_back(3, 1);
                    R1.push_back(R3.back());
                    R3.pop_back();
                }
            }
            while (!R2.empty()) {
                moves.emplace_back(2, 1);
                R1.push_back(R2.back());
                R2.pop_back();
            }
            while (!R3.empty()) {
                moves.emplace_back(3, 1);
                R1.push_back(R3.back());
                R3.pop_back();
            }
        }
    }
    if (R3.size() != n) {
        while (!R2.empty() && !R3.empty()) {
            if (R2.back() < R3.back()) {
                moves.emplace_back(2, 1);
                R1.push_back(R2.back());
                R2.pop_back();
            } else {
                moves.emplace_back(3, 1);
                R1.push_back(R3.back());
                R3.pop_back();
            }
        }
        while (!R2.empty()) {
            moves.emplace_back(2, 1);
            R1.push_back(R2.back());
            R2.pop_back();
        }
        while (!R3.empty()) {
            moves.emplace_back(3, 1);
            R1.push_back(R3.back());
            R3.pop_back();
        }
        for (int i = 0; i < n; ++i) {
            moves.emplace_back(1, 3);
        }
    }
    assert((int)moves.size() <= 2 * n * n);
    cout << (int)moves.size() << "\n";
    for (auto& [from, to] : moves) {
        cout << from << " " << to << "\n";
    }
}
