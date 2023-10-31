class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int n = pref.size();
        vector<int> ans;
        ans.push_back(pref[0]);
        // ans[0] = pref[0];
        for (int i = 0; i < n - 1; i++)
        {
            int ANS = pref[i] ^ pref[i + 1];
            ans.push_back(ANS);
        }
        return ans;
    }
};