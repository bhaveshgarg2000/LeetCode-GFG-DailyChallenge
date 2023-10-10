class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        for (int j = 1; j <= s.size(); j++)
        {
            // if we found that j == empty or j == to the size of the string then we will reverse of string according to the space needed
            if (s[j] == ' ' || j == s.size())
            {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
                ;
            }
        }
        return s;
    }
};