class Solution
{

public:
    int maxDotProduct(int n, int m, int a[], int b[])
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 1; j <= m; j++)
        {
            prev[j] = -1e9;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int notpick = 0 + prev[j];
                int pick = a[i - 1] * b[j - 1] + prev[j - 1];

                curr[j] = max(notpick, pick);
            }
            prev = curr;
        }
        return prev[m];
    }
};