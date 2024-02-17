class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for (int i = 0; (2 * i) + 1 < n; i += 1)
        {
            if (arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2])
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
};w