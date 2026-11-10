#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {
        int temp = arr[start]; // Save the starting element
        arr[start] = arr[end]; // Overwrite start with end
        arr[end] = temp;       // Assign saved start to end

        start++; // Move forward
        end--;   // Move backward
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
