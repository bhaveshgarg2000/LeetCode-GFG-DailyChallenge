class Solution
{
private:
    long long dfs(int left, int right, int arr[], vector<vector<int>> &dp)
    {
        if (left > right)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];

        long long takeLeft = arr[left] + min(dfs(left + 2, right, arr, dp), dfs(left + 1, right - 1, arr, dp));
        long long takeRight = arr[right] + min(dfs(left + 1, right - 1, arr, dp), dfs(left, right - 2, arr, dp));

        return dp[left][right] = max(takeLeft, takeRight);
    }

public:
    long long maximumAmount(int n, int arr[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(0, n - 1, arr, dp);
    }
};