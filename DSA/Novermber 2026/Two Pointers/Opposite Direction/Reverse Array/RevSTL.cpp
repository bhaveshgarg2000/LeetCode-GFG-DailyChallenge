#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int start = 0;
    int end = arr.size() - 1;
    reverse(arr.begin() + start, arr.begin() + end + 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}