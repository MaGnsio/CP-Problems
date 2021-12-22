/**
 *    author:  MaGnsi0
 *    created: 05.11.2021 20:43:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (count(a.begin(), a.end(), 1) == n) {
        cout << "lowie";
    } else if (n & 1) {
        cout << (sum & 1 ? "lowie" : "imitater");
    } else {
        int mini = *min_element(a.begin(), a.end());
        if ((sum % 2 == 0) && (mini % 2 == 0)) {
            cout << "imitater";
        } else {
            cout << "lowie";
        }
    }
}

/*
 * n is even
 *     smallest is odd
 *         sum is odd: lowie wins 
 *         sum is even: lowie wins
 *     smallest is even
 *         sum is odd: lowie wins
 *         sum is even: imitater wins
 */
