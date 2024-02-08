class Solution {
public:
    // Function to solve the problem using memoization
    int solveMem(int n, vector<int> &dp) {
        // If n is already 0, we don't need any squares, so return 0
        if (n == 0) {
            return n;
        }
        // If dp[n] is not -1, it means we have already computed the solution for n,
        // so we return it directly to avoid redundant computation
        if (dp[n] != -1) {
            return dp[n];
        }
        // Initializing answer as n, since in the worst case, we can represent n as
        // sum of n 1^2's.
        int ans = n;
        // Loop to find the minimum number of perfect square numbers required to sum up to n
        for (int i = 1; i * i <= n; i++) {
            // Considering i^2 as a perfect square
            int temp = i * i;
            // Recursively calling solveMem to find the solution for n - temp (remaining value)
            // and adding 1 to account for the current perfect square (i^2) being used.
            ans = min(ans, 1 + solveMem(n - temp, dp));
        }
        // Storing the computed answer in dp[n] for future reference
        dp[n] = ans;
        // Returning the minimum number of perfect square numbers required to sum up to n
        return dp[n];
    }
    
    // Main function to calculate the minimum number of perfect square numbers required
    // to sum up to n
    int numSquares(int n) {
        // Initializing a vector dp of size (n + 1) to store the results of subproblems.
        // -1 is used to indicate that the result for a particular value of n has not been computed yet.
        vector<int> dp(n + 1, -1);
        // Calling the solveMem function to compute the result using memoization
        return solveMem(n, dp);
    }
};
