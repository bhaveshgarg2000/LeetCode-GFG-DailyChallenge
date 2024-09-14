class Solution
{
public:
    vector<int> constructLowerArray(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> temp(n);
        vector<int> ans(n, 0);
        vector<pair<int, int>> arr1(n);

        for (int i = 0; i < n; i++)
        {
            pair<int, int> temp;
            temp.first = arr[i];
            temp.second = i;
            arr1[i] = temp;
        }
        mergesort(arr1, temp, 0, n - 1, ans);
        return ans;
    }
    void merge(vector<pair<int, int>> &arr1, vector<pair<int, int>> &temp,
               int left, int mid,
               int right, vector<int> &ans)
    {
        int i = left;
        int j = mid + 1;
        int k = left;
        while (i <= mid && j <= right)
        {
            if (arr1[i].first <= arr1[j].first)
            {
                temp[k] = arr1[j];
                k++;
                j++;
            }
            else
            {
                temp[k] = arr1[i];
                ans[arr1[i].second] += right - j + 1;
                k++;
                i++;
            }
        }

        while (i <= mid)
            temp[k++] = arr1[i++];

        while (j <= right)
            temp[k++] = arr1[j++];

        for (int i = left; i <= right; i++)
        {
            arr1[i] = temp[i];
        }
    }

    void mergesort(vector<pair<int, int>> &arr1, vector<pair<int, int>> &temp,
                   int left, int right,
                   vector<int> &ans)
    {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        mergesort(arr1, temp, left, mid, ans);
        mergesort(arr1, temp, mid + 1, right, ans);
        merge(arr1, temp, left, mid, right, ans);
    }
};