class Solution
{
public:
    int min_operations(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] >= (nums[j] + (i - j)))
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int mx = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            mx = max(mx, dp[i]);
        }
        return nums.size() - mx;
    }
};