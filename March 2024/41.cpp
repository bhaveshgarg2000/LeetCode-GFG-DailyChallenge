class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            int element = nums[i];
            // Check if the current element is in the valid range [1, n]
            if (element >= 1 && element <= n) {
                // Calculate the index where the current element should be placed
                int chair = element - 1;
                // If the element at 'chair' index is not equal to the current element
                if (nums[chair] != element) {
                    // Swap the current element with the element at 'chair' index
                    swap(nums[chair], nums[i]);
                    // Decrement i to revisit the swapped element
                    i--;
                }
            }
        }

        // Iterate through the array again to find the first missing positive integer
        for (int i = 0; i < n; i++) {
            if (i + 1 != nums[i]) {
                // If the index doesn't match the element at that index, return the missing positive integer
                return i + 1;
            }
        }

        // If all elements from 1 to n are present, return n + 1
        return n + 1;
    }
};
