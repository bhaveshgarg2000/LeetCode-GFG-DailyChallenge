class Solution
{
public:
    string greatestLetter(string s)
    {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (islower(s[i]))
            {
                lower[s[i] - 'a'] = 1;
            }
            else
            {
                upper[s[i] - 'A'] = 1;
            }
        }
        for (int i = 25; i >= 0; i--)
        {
            if (lower[i] && upper[i])
            {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};