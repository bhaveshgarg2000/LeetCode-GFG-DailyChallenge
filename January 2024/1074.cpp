class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;         // Variable to store the current prefix sum
        int count = 0;       // Counter for subarrays with sum equal to k
        map<int, int> mp;    // Map to store the frequency of prefix sums
        int n = nums.size(); // Size of the input array

        // Iterate through the array
        for (int i = 0; i < n; i++)
        {
            // Calculate the prefix sum
            sum += nums[i];

            // If the current prefix sum is equal to k, increment count
            if (sum == k)
            {
                count++;
            }

            // If there exists a prefix sum (sum - k) in the map,
            // add its frequency to the count
            if (mp.find(sum - k) != mp.end())
            {
                count += mp[sum - k];
            }

            // Update the frequency of the current prefix sum in the map
            mp[sum]++;
        }

        return count; // Return the total count of subarrays with sum equal to k
    }

public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            vector<int> sum(n, 0);
            for (int j = i; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    sum[k] += matrix[j][k];
                }
                count += subarraySum(sum, target);
            }
        }
        return count;
    }
};