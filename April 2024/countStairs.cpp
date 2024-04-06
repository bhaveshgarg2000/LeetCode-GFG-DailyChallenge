class Solution
{
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n)
    {
        if (n % 2 == 0)
        {
            long long ans = n / 2;w
            ans = ans + 1;
            return ans;
        }
        else
        {
            n = n - 1;
            long long ans = n / 2;
            ans = ans + 1;
            return ans;
        }
    }
};