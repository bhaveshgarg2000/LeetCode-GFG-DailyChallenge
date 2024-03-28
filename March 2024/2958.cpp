class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size(); // Get the size of the input vector
        map<int, int> mpp;   // Initialize a map to store element frequencies
        int i = 0;           // Left pointer of the sliding window
        // Right pointer of the sliding window
        int j = 0;
        // Initialize the answer variable to 1 (minimum possible length)
        int ans = 1;

        while (i < n && j < n)
        {
            mpp[nums[j]]++; // Increase the frequency of the current element

            while (mpp[nums[j]] > k)
            {
                // Shrink the window if any element's frequency exceeds k
                mpp[nums[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1); // Update the maximum length found so far
            j++;                       // Move the right pointer to the next element
        }

        return ans; // Return the maximum length of subarray with at most k
                    // frequency
    }
};
