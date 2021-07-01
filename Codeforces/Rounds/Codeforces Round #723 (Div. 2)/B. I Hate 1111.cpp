//https://codeforces.com/contest/1526/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    //Since gcd(11,111)=1, by the Chicken McNugget Theorem, all numbers greater than 1099 can be written as a sum of 11 and 111.
    //We can use brute force to find the answer to all values less than or equal to 1099 and answer yes for all other numbers.
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << (N >= 111 * (N % 11) ? "YES\n" : "NO\n");
    }
}
