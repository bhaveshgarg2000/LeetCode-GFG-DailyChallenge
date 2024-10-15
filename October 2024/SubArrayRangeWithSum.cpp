class Solution
{
public:
    int subArraySum(vector<int> &arr, int tar)
    {
        unordered_map<int, int> mpp;
        int sum = 0;
        int ans = 0;
        for (int x : arr)
        {
            sum += x;
            if (sum == tar)
            {
                ans++;
            }
            if (mpp.find(sum - tar) != mpp.end())
            {
                ans += mpp[sum - tar];
            }
            mpp[sum]++;
        }
        return ans;
    }
};