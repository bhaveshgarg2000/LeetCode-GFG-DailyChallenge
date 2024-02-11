class Solution
{
public:
    vector<int> recamanSequence(int n)
    {
        // code here
        vector<int> ans = {0};
        unordered_set<int> inc;
        for (int i = 1; i < n; i++)
        {
            int add = ans.back() + i;
            int sub = ans.back() - i;
            if (sub > 0 and (inc.find(sub) == inc.end()))
            {
                ans.push_back(sub);
                inc.insert(sub);
            }
            else
            {
                ans.push_back(add);
                inc.insert(add);
            }
        }
        return ans;
    }
};