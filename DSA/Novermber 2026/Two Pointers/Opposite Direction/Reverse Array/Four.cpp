#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Approach
    // Here Simply reading values fom original Array[arr] in reverse order and pushing them into new array[ans] and printing the new array[ans] at the end.
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<int> ans;
    int i = arr.size() - 1;
    while (i >= 0)
    {
        ans.push_back(arr[i]);
        i--;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}