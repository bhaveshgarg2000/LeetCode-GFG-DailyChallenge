class Solution
{
    static bool cmp(string &s1, string &s2)
    {
        return s1 + s2 > s2 + s1;
    }

public:
    string printLargest(int n, vector<string> &arr)
    {
        // code here
        sort(arr.begin(), arr.end(), cmp);
        string ans = "";
        for (int i = 0; i < arr.size(); i++)
        {
            ans += arr[i];
        }
        return ans;
    }
};