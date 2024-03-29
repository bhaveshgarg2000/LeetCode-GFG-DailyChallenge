class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        map<int, int> mpp;
        int n = nums.size();
        int a = 0;
        for (auto i : nums)
        {
            a = max(a, i);
        }
        int i = 0;
        int j = 0;
        long long ans = 0;
        while (j < n)
        {
            mpp[nums[j]]++;
            while (mpp[a] >= k)
            {
                ans = ans + n - j;
                mpp[nums[i]]--;
                i++;
            }
            j++;
        }

        return ans;
    }
};