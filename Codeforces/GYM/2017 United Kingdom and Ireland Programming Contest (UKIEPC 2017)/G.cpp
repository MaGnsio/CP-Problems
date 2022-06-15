/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 19:31:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cur_x1, cur_y1, cur_z1;
    cin >> cur_x1 >> cur_y1 >> cur_z1;
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    int cur_x2, cur_y2, cur_z2;
    cin >> cur_x2 >> cur_y2 >> cur_z2;
    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;
    auto print_locations = [&]() {
        cout << "(" << cur_x1 << " " << cur_y1 << " " << cur_z1 << ") ";
        cout << "(" << cur_x2 << " " << cur_y2 << " " << cur_z2 << ")\n";
    };
    auto not_equal = [](int cur_x1, int cur_y1, int cur_z1, int cur_x2, int cur_y2, int cur_z2) {
        return ((cur_x1 != cur_x2) || (cur_y1 != cur_y2) || (cur_z1 != cur_z2));
    };
    print_locations();
    while (cur_x1 != x1 || cur_y1 != y1 || cur_z1 != z1 || cur_x2 != x2 || cur_y2 != y2 || cur_z2 != z2) {
        if (cur_x1 < x1 && not_equal(cur_x1 + 1, cur_y1, cur_z1, cur_x2, cur_y2, cur_z2)) {
            cur_x1++;
        } else if (cur_x1 > x1 && not_equal(cur_x1 - 1, cur_y1, cur_z1, cur_x2, cur_y2, cur_z2)) {
            cur_x1--;
        } else if (cur_y1 < y1 && not_equal(cur_x1, cur_y1 + 1, cur_z1, cur_x2, cur_y2, cur_z2)) {
            cur_y1++;
        } else if (cur_y1 > y1 && not_equal(cur_x1, cur_y1 - 1, cur_z1, cur_x2, cur_y2, cur_z2)) {
            cur_y1--;
        } else if (cur_z1 < z1 && not_equal(cur_x1, cur_y1, cur_z1 + 1, cur_x2, cur_y2, cur_z2)) {
            cur_z1++;
        } else if (cur_z1 > z1 && not_equal(cur_x1, cur_y1, cur_z1 - 1, cur_x2, cur_y2, cur_z2)) {
            cur_z1--;
        } else if (!not_equal(x2, y2, z2, cur_x2, cur_y2, cur_z2)) {
            int dx = x1 - cur_x1, dy = y1 - cur_y1, dz = z1 - cur_z1;
            if (dx) {
                cur_y1--;
                print_locations();
                cur_x1 += (dx < 0 ? -1 : 1);
                print_locations();
                cur_x1 += (dx < 0 ? -1 : 1);
                print_locations();
                cur_y1++;
            } else if (dy) {
                cur_x1--;
                print_locations();
                cur_y1 += (dy < 0 ? -1 : 1);
                print_locations();
                cur_y1 += (dy < 0 ? -1 : 1);
                print_locations();
                cur_x1++;
            } else if (dz) {
                cur_y1--;
                print_locations();
                cur_z1 += (dz < 0 ? -1 : 1);
                print_locations();
                cur_z1 += (dz < 0 ? -1 : 1);
                print_locations();
                cur_z1++;
            } else {
                assert(1 == 0);
            }
        }
        if (!not_equal(x2, y2, z2, cur_x2, cur_y2, cur_z2)) {
            print_locations();
            continue;
        }
        if (cur_x2 < x2 && not_equal(cur_x1, cur_y1, cur_z1, cur_x2 + 1, cur_y2, cur_z2)) {
            cur_x2++;
        } else if (cur_x2 > x2 && not_equal(cur_x1, cur_y1, cur_z1, cur_x2 - 1, cur_y2, cur_z2)) {
            cur_x2--;
        } else if (cur_y2 < y2 && not_equal(cur_x1, cur_y1, cur_z1, cur_x2, cur_y2 + 1, cur_z2)) {
            cur_y2++;
        } else if (cur_y2 > y2 && not_equal(cur_x1, cur_y1, cur_z1, cur_x2, cur_y2 - 1, cur_z2)) {
            cur_y2--;
        } else if (cur_z2 < z2 && not_equal(cur_x1, cur_y1, cur_z1, cur_x2, cur_y2, cur_z2 + 1)) {
            cur_z2++;
        } else if (cur_z2 > z2 && not_equal(cur_x1, cur_y1, cur_z1, cur_x2, cur_y2, cur_z2 - 1)) {
            cur_z2--;
        } else {
            int dx = x2 - cur_x2, dy = y2 - cur_y2, dz = z2 - cur_z2;
            if (dx) {
                cur_y2--;
                print_locations();
                cur_x2 += (dx < 0 ? -1 : 1);
                print_locations();
                cur_x2 += (dx < 0 ? -1 : 1);
                print_locations();
                cur_y2++;
            } else if (dy) {
                cur_x2--;
                print_locations();
                cur_y2 += (dy < 0 ? -1 : 1);
                print_locations();
                cur_y2 += (dy < 0 ? -1 : 1);
                print_locations();
                cur_x2++;
            } else if (dz) {
                cur_y2--;
                print_locations();
                cur_z2 += (dz < 0 ? -1 : 1);
                print_locations();
                cur_z2 += (dz < 0 ? -1 : 1);
                print_locations();
                cur_z2++;
            } else {
                assert(1 == 0);
            }
        }
        print_locations();
    }
}
