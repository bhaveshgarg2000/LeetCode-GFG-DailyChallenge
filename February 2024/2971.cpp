class Solution
{
public:
    // Function to find the largest perimeter possible
    long long largestPerimeter(vector<int> &nums)
    {
        // Get the size of the input vector
        int n = nums.size();

        // Sort the vector in non-decreasing order
        sort(nums.begin(), nums.end());

        // Initialize variables for perimeter and remaining sum
        long long peri = 0;
        long long remainSum = 0;

        // Iterate through the sorted vector
        for (int i = 0; i < n; i++)
        {
            // Check if the current element is smaller than the remaining sum
            if (nums[i] < remainSum)
            {
                // If it is, update the perimeter by adding the current element
                peri = remainSum + nums[i];
            }
            // Update the remaining sum by adding the current element
            remainSum += nums[i];
        }

        // If no valid perimeter was found, return -1; otherwise, return the perimeter
        return peri == 0 ? -1 : peri;
    }
};
