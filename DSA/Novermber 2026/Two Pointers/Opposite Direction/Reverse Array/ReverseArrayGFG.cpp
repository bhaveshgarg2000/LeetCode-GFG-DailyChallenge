class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            swap(arr[start++], arr[end--]);
        }
        // recursiveArrayReverse(arr,start,end);
    }
    void recursiveArrayReverse(vector<int> &arr, int start, int end)
    {
        // Base Condition
        if (start >= end)
        {
            return;
        }

        // Swap Arr Elements
        swap(arr[start], arr[end]);

        // Recursive Call to Reverse Array
        recursiveArrayReverse(arr, start + 1, end - 1);
    }
};

// Time Complexity: O(n)
// This Piece of Code Contains both iterative and recursive methods to reverse an array.
// The `reverseArray` function uses a two-pointer approach to swap elements from the start and end of the array until they meet in the middle.
// The `recursiveArrayReverse` function is a recursive implementation that swaps elements and makes recursive calls until the base condition is met.

// Both methods achieve the same result of reversing the array in place.