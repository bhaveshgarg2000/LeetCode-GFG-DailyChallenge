class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0; // If input vector is empty, return 0 as there are no subarrays.
        }
        int cnt = 0;     // Counter for valid subarrays.
        long long p = 1; // Initialize product variable to 1.
        int start = 0;   // Initialize start of subarray index.

        // Iterate through the input vector from start to end.
        for (int end = 0; end < n; end++)
        {
            p *= nums[end]; // Update product by multiplying with current element.

            // Check if product is greater than or equal to k.
            while (start <= end && p >= k)
            {
                p /= nums[start++]; // Update product by dividing out the start element.
            }

            // Add the number of valid subarrays to the count.
            cnt += (end - start + 1);
        }

        return cnt; // Return the total count of valid subarrays.
    }
};
