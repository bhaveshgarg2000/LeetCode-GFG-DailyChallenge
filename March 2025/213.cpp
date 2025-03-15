class Solution
{
public:
    int robHelper(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }
        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            int curr = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> skipFirst(n - 1);
        vector<int> skipLast(n - 1);

        for (int i = 0; i < n - 1; i++)
        {
            skipLast[i] = nums[i];      // Copying first n-1 elements
            skipFirst[i] = nums[i + 1]; // Copying last n-1 elements
        }

        int skippingLast = robHelper(skipLast);
        int skippingFirst = robHelper(skipFirst);
        int maxLoot = max(skippingLast, skippingFirst);
        return maxLoot;
    }
};