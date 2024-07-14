class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
        {
            return false;
        }

        int i = 0;

        // Ascend to the peak
        while (i + 1 < n && arr[i] < arr[i + 1])
        {
            i++;
        }

        // Peak can't be first or last
        if (i == 0 || i == n - 1)
        {
            return false;
        }

        // Descend from the peak
        while (i + 1 < n && arr[i] > arr[i + 1])
        {
            i++;
        }

        // Check if we reached the end of the array
        return i == n - 1;
    }
};
