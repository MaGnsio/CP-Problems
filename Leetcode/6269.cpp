/**
 *    author:  MaGnsi0
 *    created: 25.12.2022 06:11:24
**/

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        vector<int> j;
        for (int i = 0; i < (int)words.size(); ++i) {
            if (words[i] == target) {
                j.push_back(i);
            }
        }
        if (j.empty()) {
            return -1;
        } else {
            int ans = (int)words.size();
            for (int i = 0; i < (int)j.size(); ++i) {
                int k = startIndex;
                if (k < j[i]) {
                    swap(k, j[i]);
                }
                ans = min({ans, k - j[i], (int)words.size() - k + j[i]});
            }
            return ans;
        }
    }
};
