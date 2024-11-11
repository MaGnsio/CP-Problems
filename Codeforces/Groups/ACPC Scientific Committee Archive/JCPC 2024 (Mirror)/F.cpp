/**
 *    author:  MaGnsi0
 *    created: 11.11.2024 19:03:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t a; cin >> a;
    int64_t b; cin >> b;
    int64_t x; cin >> x;
    vector<int> A, B;
    for (int bit = 30; bit >= 0; --bit) {
        if (!(x >> bit & 1)) { break; }
        if (!(a >> bit & 1)) {
            a |= 1LL << bit;
            A.push_back(bit);
        }
        if (!(b >> bit & 1)) {
            b |= 1LL << bit;
            B.push_back(bit);
        }
    }
    if ((a & b) < x) {
        for (int bit = 30; bit >= 0; --bit) {
            if (!(a >> bit & 1) != !(b >> bit & 1)) {
                int64_t new_a = a | (1LL << bit);
                int64_t new_b = b | (1LL << bit);
                if ((new_a & new_b) >= x) {
                    if (!(a >> bit & 1)) {
                        a |= 1LL << bit;
                        A.push_back(bit);
                    }
                    if (!(b >> bit & 1)) {
                        b |= 1LL << bit;
                        B.push_back(bit);
                    }
                }
                break;
            }
        }
    }
    if ((a & b) < x) {
        for (int bit = 30; bit >= 0; --bit) {
            if (!(a >> bit & 1)) {
                A.push_back(bit);
                B.push_back(bit);
                break;
            }
        }
    }
    cout << (int)A.size() + (int)B.size() << "\n";
    for (int bit : A) {
        cout << "a " << bit << "\n";
    }
    for (int bit : B) {
        cout << "b " << bit << "\n";
    }
}
