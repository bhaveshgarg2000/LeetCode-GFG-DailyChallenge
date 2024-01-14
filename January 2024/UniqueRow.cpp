// GFG

class Solution
{
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N)
    {
        // Your code here
        set<vector<int>> s;
        vector<int> ans;
        for (int i = 0; i < M; i++)
        {
            if (s.count(matrix[i]))
            {
                ans.push_back(i);
            }
            else
            {
                s.insert(matrix[i]);
            }
        }
        return ans;
    }
};
