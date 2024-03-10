class Solution
{
public:
    string removeDuplicates(string str)
    {
        string ans = "";
        unordered_map<char, int> mp;
        for (int i : str)
        {
            mp[i]++;
        }
        for (int i = str.size(); i >= 0; i--)
        {
            if (mp[str[i]] > 1)
            {
                mp[str[i]]--;
            }
            else
            {
                ans += str[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};