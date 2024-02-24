class Solution
{
public:
    int maxSum(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        int a = n / 2;
        int b = n / 3;
        int c = n / 4;

        int ans = maxSum(a) + maxSum(b) + maxSum(c);
        return max(ans, n);
    }
};