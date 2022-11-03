/**
 *    author:  MaGnsi0
 *    created: 02.07.2022 16:30:02
**/
#include <bits/stdc++.h>

using namespace std;

const string day[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

//fri -> mon -> wed
//tue -> thu -> mon

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string start_day;
    cin >> start_day >> n;
    int start_day_idx;
    for (int i = 0; i < 7; ++i) {
        if (start_day == day[i]) {
            start_day_idx = i;
        }
    }
    function<int(int)> solve = [&](int x) {
        string deposit_day = day[((start_day_idx - x) % 7 + 7) % 7];
        assert(deposit_day != "Sat" && deposit_day != "Sun");
        if (deposit_day == "Tue") {
            x -= 30;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Thu";
        }
        if (deposit_day == "Thu") {
            x -= 32;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Mon";
        }
        if (deposit_day == "Wed") {
            x -= 30;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Fri";
        }
        if (deposit_day == "Fri") {
            x -= 31;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Mon";
        }
        x %= 91;
        if (deposit_day == "Tue") {
            x -= 30;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Thu";
        }
        if (deposit_day == "Thu") {
            x -= 32;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Mon";
        }
        if (deposit_day == "Mon") {
            x -= 30;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Wed";
        }
        if (deposit_day == "Wed") {
            x -= 30;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Fri";
        }
        if (deposit_day == "Fri") {
            x -= 31;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Mon";
        }
        if (deposit_day == "Mon") {
            x -= 30;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Wed";
        }
        if (deposit_day == "Wed") {
            x -= 30;
            if (x <= 0) {
                return (-x);
            }
            deposit_day = "Fri";
        }
    };
    int ans = 50;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans = min(ans, solve(x));
    }
    cout << ans;
}
