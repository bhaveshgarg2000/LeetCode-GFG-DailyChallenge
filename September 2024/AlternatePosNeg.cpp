
class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pos, neg;

        // Separate positive and negative numbers into two arrays
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                pos.push_back(arr[i]); // Push positive numbers
            }
            else
            {
                neg.push_back(arr[i]); // Push negative numbers
            }
        }

        int p = 0, q = 0, i = 0;

        // Rearrange alternating positive and negative numbers
        while (p < pos.size() && q < neg.size())
        {
            arr[i++] = pos[p++]; // Add positive number
            arr[i++] = neg[q++]; // Add negative number
        }

        // Add remaining positive numbers (if any)
        while (p < pos.size())
        {
            arr[i++] = pos[p++];
        }

        // Add remaining negative numbers (if any)
        while (q < neg.size())
        {
            arr[i++] = neg[q++];
        }
    }
};
