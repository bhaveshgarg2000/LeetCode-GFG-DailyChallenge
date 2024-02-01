class Solution
{
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string s)
    {
        vector<int> check(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                check[s[i] - 'a']++;
            if (s[i] >= 'A' && s[i] <= 'Z')
                check[s[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (check[i] == 0)
                return false;
        }
        return true;
    }
};