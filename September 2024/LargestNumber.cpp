bool compare(int a, int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), compare);
        string ans = "";
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ans += to_string(nums[i]);
        }

        if (ans[0] == '0')
        {
            return "0";
        }
        return ans;
    }
};