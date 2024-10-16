class Solution
{
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int> &arr)
    {
        // Your code goes here.
        int n = arr.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (auto x : arr)
        {
            mpp[x]++;
        }

        for (auto it : mpp)
        {
            if (it.second > n / 3)
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.size() == 0)
        {
            return {-1};
        }

        return ans;
    }
};