#include <iostream>
#include <vector>
#include <algorithm> // Required for swap

using namespace std;
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter Elements of Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    cout << "Reversed Array: ";
    printArray(arr);

    return 0;
}
