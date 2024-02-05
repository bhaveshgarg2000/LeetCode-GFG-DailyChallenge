class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> st;
        for (char ch : s)
        {
            st[ch]++;
        }
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (st[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};