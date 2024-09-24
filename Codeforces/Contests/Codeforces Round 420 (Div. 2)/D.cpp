/**
 *    author:  MaGnsi0
 *    created: 24.09.2024 18:29:52
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    vector<pair<int, int>> p(k);
    for (int i = 0; i < k; ++i) {
        int x; cin >> x; x--;
        int y; cin >> y; y--;
        p[i] = make_pair(x, y);
    }
    sort(p.begin(), p.end());
    map<int, vector<pair<int, int>>> rows, cols;
    for (int i = 0; i < k; ++i) {
        rows[p[i].first].emplace_back(p[i].second, i);
        cols[p[i].second].emplace_back(p[i].first, i);
    }
    vector d(k + 1, vector<int>(3, OO));
    set<tuple<int, int, int>> S;
    d[0][2] = 0; S.emplace(0, 0, 2);
    while (!S.empty()) {
        auto [dv, jv, sv] = *S.begin();
        S.erase(S.begin());
        if (dv != d[jv][sv]) { continue; }
        int rv = p[jv].first;
        int cv = p[jv].second;
        for (auto [cu, ju] : rows[rv - 2]) {
            if (sv == 0 && cu == cv) {
                int su = 2;
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 2;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [cu, ju] : rows[rv - 1]) {
            if (sv == 1 || cu == cv) {
                int su = 2;
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 1;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [cu, ju] : rows[rv - 1]) {
            if (sv == 1 || cu == cv) {
                int su = 2;
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 1;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [cu, ju] : rows[rv]) {
            if (sv == 1 || abs(cu - cv) <= 1) {
                int su = (sv == 0 ? 2 : sv);
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 1;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [cu, ju] : rows[rv + 1]) {
            if (sv == 1 || cu == cv) {
                int su = 2;
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 1;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [cu, ju] : rows[rv + 2]) {
            if (sv == 0 && cu == cv) {
                int su = 2;
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 2;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [ru, ju] : cols[cv - 2]) {
            if (sv == 1 && ru == rv) {
                int su = 2;
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 2;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [ru, ju] : cols[cv - 1]) {
            if (sv == 0 || ru == rv) {
                int su = 2;
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 0;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [ru, ju] : cols[cv]) {
            if (sv == 0 || abs(ru - rv) <= 1) {
                int su = (sv == 1 ? 2 : sv);
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 0;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [ru, ju] : cols[cv + 1]) {
            if (sv == 0 || ru == rv) {
                int su = 2;
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 0;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
        for (auto [ru, ju] : cols[cv + 2]) {
            if (sv == 1 && ru == rv) {
                int su = 2;
                if (d[jv][sv] < d[ju][su]) {
                    d[ju][su] = d[jv][sv];
                    S.emplace(d[ju][su], ju, su);
                }
            } else {
                int su = 2;
                if (d[jv][sv] + 1 < d[ju][su]) {
                    d[ju][su] = d[jv][sv] + 1;
                    S.emplace(d[ju][su], ju, su);
                }
            }
        }
    }
    int ans = OO;
    for (int i = 0; i < k; ++i) {
        int rv = p[i].first;
        int cv = p[i].second;
        int ru = n - 1;
        int cu = m - 1;
        if (ru == rv && cu == cv) {
            ans = min({ans, d[i][0], d[i][1], d[i][2]});
        }
        if (ru == rv) {
            ans = min(ans, d[i][2] + 1);
            ans = min(ans, d[i][1]);
            ans = min(ans, d[i][0] + 1);
        } else if (rv + 1 == ru) {
            ans = min(ans, d[i][2] + 1);
            ans = min(ans, d[i][1] + 1);
            ans = min(ans, d[i][0] + 1);
        }
        if (cu == cv) {
            ans = min(ans, d[i][2] + 1);
            ans = min(ans, d[i][1] + 1);
            ans = min(ans, d[i][0]);
        } else if (cv + 1 == cu) {
            ans = min(ans, d[i][2] + 1);
            ans = min(ans, d[i][1] + 1);
            ans = min(ans, d[i][0] + 1);
        }
    }
    cout << (ans == OO ? -1 : ans) << "\n";
}
