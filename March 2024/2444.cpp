class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long res = 0; // Initialize the result variable to store the count
                           // of valid subarrays
        int start = 0;     // Initialize the start index of the current subarray
        int minStart = 0;  // Initialize the index of the last occurrence of minK
        int maxStart =
            0; // Initialize the index of the last occurrence of maxK
               // Flag to track if minK is found in the current subarray
        bool minF = false;
        bool maxF =
            false;           // Flag to track if maxK is found in the current subarray
        int n = nums.size(); // Get the size of the input array

        // Iterate through the elements of the array
        for (int i = 0; i < n; i++)
        {
            int num = nums[i]; // Get the current element
            // Check if the current element is outside the
            // range [minK, maxK]
            if (num < minK || num > maxK)
            {
                // Reset flags and update the start index for the next subarray
                minF = false;
                maxF = false;
                start = i + 1;
            }

            // Check if the current element is equal to minK
            if (num == minK)
            {
                minF = true;  // Set the minF flag to true
                minStart = i; // Update the index of the last occurrence of minK
            }

            // Check if the current element is equal to maxK
            if (num == maxK)
            {
                maxF = true;  // Set the maxF flag to true
                maxStart = i; // Update the index of the last occurrence of maxK
            }

            // Check if both minK and maxK are found in the current subarray
            if (minF && maxF)
            {
                // Calculate the length of the subarray and add it to the result
                res += (min(minStart, maxStart) - start + 1);
            }
        }

        return res; // Return the count of valid subarrays
    }
};
