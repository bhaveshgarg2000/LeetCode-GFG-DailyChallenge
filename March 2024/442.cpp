class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                res.push_back(abs(nums[i]));
            }
            nums[index] = -nums[index];
        }
        return res;
    }
};