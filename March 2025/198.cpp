class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        // If there's no house, return 0
        if (n == 0)
            return 0;
        // If there's only one house, return its value
        if (n == 1)
            return nums[0];

        // vector<int> dp(n);
        // dp[0] = nums[0];  // Max money from first house
        // dp[1] = max(nums[0], nums[1]);  // Max from first two houses
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        // Fill dp array: choose to rob current house + dp[i-2] or skip it (dp[i-1])
        for (int i = 2; i < n; i++)
        {
            // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        // return dp[n - 1];  // Max money that can be robbed
        return prev1; // Max money that can be robbed
    }
};
