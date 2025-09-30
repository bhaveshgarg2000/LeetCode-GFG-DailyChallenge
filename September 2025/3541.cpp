class Solution {
private:
    int isVowel(char ch) {
        if ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') ||
            (ch == 'u')) {
            return 1;
        }
        return 0;
    }

public:
    int maxFreqSum(string s) {
        int freq[26];
        int maxVow = 0;
        int maxCon = 0;
        for (char c : s) {
            int i = c - 'a';
            freq[i]++;
            if(isVowel(c)){
                maxVow = max(maxVow,freq[i]);
            }else{
                maxCon = max(maxCon,freq[i]);
            }
        }
        return maxVow + maxCon;
    }
};