class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // arrs sorted
        // [4,5,9]
        // [4,8,9,4]
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            // checking if current index element == last elemnt then will not process that  element using continue keyword
            if (i > 0 && nums1[i - 1] == nums1[i])
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    ans.push_back(nums1[i]);
                    break;
                }
            }
        }
        return ans;
    }
};