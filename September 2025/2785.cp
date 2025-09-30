class Solution {
private:
    bool isVowel(char c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') ||
               (c == 'u') || (c == 'A') || (c == 'E') || (c == 'I') ||
               (c == 'O') || (c == 'U');
    }

public:
    string sortVowels(string s) {
        string t;
        string s1 = "";
        for (auto i : s) {
            if (isVowel(i)) {
                s1 += i;
            }
        }
        sort(s1.begin(), s1.end());
        int index = 0;
        for (auto i : s) {
            if (isVowel(i)) {
                t += s1[index++];
            } else {
                t += i;
                
            }
        }
        return t;
    }
};