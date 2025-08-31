#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> path;
        backTrack(s, 0, path, res);
        return res;
    }

private:
    void backTrack(const string& s, int i, vector<string>& path, vector<string>& res) {
        if (path.size() == 4) {
            if (i == s.size()) {
                res.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }

        int remainingParts = 4 - path.size();
        int remainingChars = s.size() - i;
        if (remainingChars < remainingParts || remainingChars > remainingParts * 3) return;

        for (int len = 1; len <= 3 && i + len <= s.size(); len++) {
            string part = s.substr(i, len);
            if (!isValid(part)) continue;

            path.push_back(part);
            backTrack(s, i + len, path, res);
            path.pop_back();
        }
    }

    bool isValid(const string& s) {
        if (s.size() > 1 && s[0] == '0') return false; // leading zero
        if (s.size() > 3) return false;
        int num = stoi(s);
        return num <= 255;
    }
};
