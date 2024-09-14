#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        // code here
        int sum = 0;
        int firstSum = 0;
        for (auto i : arr)
        {
            sum += i;
        }
        for (auto i : arr)
        {
            sum -= i;
            firstSum += i;

            if (firstSum == sum)
            {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp)
        {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
