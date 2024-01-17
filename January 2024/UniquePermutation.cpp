class Solution
{
public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end()); // Sort the array to ensure sorted permutations
        do
        {
            result.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        return result;
    }
};