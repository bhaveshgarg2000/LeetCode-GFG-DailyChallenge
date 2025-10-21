class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(values, 0, n - 1, dp);
    }

    int helper(vector<int>& values, int start, int end, vector<vector<int>>& dp) {
        if (start + 1 == end) return 0;  // No triangle possible
        if (dp[start][end] != -1) return dp[start][end];

        int ans = INT_MAX;
        for (int k = start + 1; k < end; k++) {
            int score = values[start] * values[k] * values[end] +
                        helper(values, start, k, dp) +
                        helper(values, k, end, dp);
            ans = min(ans, score);
        }
        return dp[start][end] = ans;
    }
};
