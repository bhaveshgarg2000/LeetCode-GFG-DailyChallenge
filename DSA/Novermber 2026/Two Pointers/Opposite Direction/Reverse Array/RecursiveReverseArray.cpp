#include <bits/stdc++.h>
using namespace std;
void recursiveReverseArray(vector<int> &arr, int start, int end)
{
    // Base case: If the start index is greater than or equal to the end index, return
    if (start >= end)
    {
        return;
    }
    // Swap the elements at the start and end indices
    swap(arr[start], arr[end]);
    // Recursive call to reverse the subarray from start + 1 to end - 1
    recursiveReverseArray(arr, start + 1, end - 1);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    recursiveReverseArray(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}