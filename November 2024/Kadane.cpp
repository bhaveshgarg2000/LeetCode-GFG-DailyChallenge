class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr)
    {
        int sum = 0;
        int n = arr.size();
        int maxi = arr[0];
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxi = max(maxi, sum);
            while (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};