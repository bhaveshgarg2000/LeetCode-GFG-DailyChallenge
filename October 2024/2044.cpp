class Solution
{
public:
    void countmaxOr(vector<int> &nums, int i, int &n, int &maxor, int curror,
                    int &ans)
    {
        if (i == n)
        {
            ans += (maxor == curror);
            return;
        }

        // Two Choice :
        // Choose
        countmaxOr(nums, i + 1, n, maxor, curror | nums[i], ans);
        // NOt Choose
        countmaxOr(nums, i + 1, n, maxor, curror, ans);
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        int maxor = 0;
        for (int i = 0; i < n; i++)
        {
            maxor |= nums[i];
        }

        countmaxOr(nums, 0, n, maxor, 0, ans);
        return ans;
    }
};