class Solution
{
public:
    int getSingle(vector<int> &arr)
    {
        // code here
        int res = 0;
        for (int num : arr)
        {
            res ^= num;
        }
        return res;
    }
};