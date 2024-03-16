class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        // Initialize a map to store the running sum and its index
        unordered_map<int, int> mpp;
        int n = nums.size();

        // Convert 0s to -1s to simplify the calculation of running sum
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = -1;
            }
        }

        int sum = 0; // Initialize running sum
        int res = 0; // Initialize result

        // Iterate through the array to calculate the running sum and update result
        for (int i = 0; i < n; i++)
        {
            sum += nums[i]; // Update running sum

            // If running sum is 0, update result with current index + 1
            if (sum == 0)
            {
                res = max(res, i + 1);
            }

            // Check if the running sum has been seen before
            if (mpp.find(sum) != mpp.end())
            {
                // If yes, update result by taking the difference between current index and the previous occurrence
                res = max(res, i - mpp[sum]);
            }
            else
            {
                // If not, store the running sum along with its index in the map
                mpp[sum] = i;
            }
        }

        return res; // Return the final result
    }
};
