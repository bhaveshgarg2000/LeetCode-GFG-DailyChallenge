
class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        // METHOD 1
        // return sort(arr.begin(),arr.end());
        // METHOD 2
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                sum++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (sum > 0)
            {
                arr[i] = 0;
                sum--;
            }
            else
            {
                arr[i] = 1;
            }
        }
    }
};