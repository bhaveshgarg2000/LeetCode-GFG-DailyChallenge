class Solution
{
public:
    bool wordBreak(int n, string s, vector<string> &wordDict)
    {
        n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // Convert wordDict to unordered_set for O(1) lookup

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
                { // Use unordered_set's find for O(1) lookup
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
