class Solution
{
public:
    int rotateDelete(vector<int> &arr)
    {
        // Your code here
        int n = arr.size();
        return arr[n - (n / 2 + n / 4)];
    }
};
