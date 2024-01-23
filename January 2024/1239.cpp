class Solution
{
private:
    int maxi(vector<string> &arr, string str, int index)
    {
        unordered_set<int> s(str.begin(), str.end());
        if (s.size() != ((int)str.size()))
        {
            return 0;
        }
        int ret = str.length();
        for (int i = index; i < arr.size(); i++)
        {
            ret = max(ret, maxi(arr, str + arr[i], i + 1));
        }
        return ret;
    }

public:
    int maxLength(vector<string> &arr)
    {
        string str = "";
        int index = 0;
        return maxi(arr, str, index);
    }
};