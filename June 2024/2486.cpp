class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = t.size();
        while (i < n) {

            while (i < n && s[i] != t[j]) {
                i++;
            }
            if (i == n) {
                return m - j;
            }
            i++;
            j++;
        }
        return m - j;
    }
};