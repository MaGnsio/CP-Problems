/**
 *    author:  MaGnsi0
 *    created: 09.11.2021 13:30:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int dayNumber = n;
    for (int i = 1; i <= n; ++i) {
        if(((i + firstYear) % 4 == 0 && (i + firstYear) % 100 != 0) || ((i + firstYear) % 400 == 0)) {
            dayNumber++;
        }
    }
    dayNumber %= 7;
    string day[7] = {"Sun", "Mon", "Tues", "Wednes", "Thurs", "Fri", "Satur"};
    cout << day[dayNumber] << "day";
}
