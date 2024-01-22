class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int duplicate;
        int sum = 0;
        int n = nums.size();
        vector<bool> seen(n, false);
        for (int i : nums)
        {
            if (seen[i])
            {
                duplicate = i;
            }
            else
            {
                seen[i] = true;
                sum += i;
            }
        }
        int missing = n * (n + 1) / 2 - sum;
        return {duplicate, missing};
    }
};