class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        for (auto currInterval : intervals)
        {
            // NON OVERLAP CASE
            // New inteval is after current then push current into ans vector
            if (currInterval[1] < newInterval[0])
            {
                ans.push_back(currInterval);
                // if New inteval is comes before current then we need to make
                // it current &
                //  check for overlapping
            }
            else if (newInterval[1] < currInterval[0])
            {
                ans.push_back(newInterval);
                newInterval = currInterval;
            }
            // OVERLAPPING CASE
            else
            {
                newInterval[0] = min(currInterval[0], newInterval[0]);
                newInterval[1] = max(currInterval[1], newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};