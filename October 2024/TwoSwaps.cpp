bool checkSorted(vector<int> &arr)
{
    // code here.

    int mp = 0;

    for (int ind = 1; ind <= arr.size(); ind++)
    {
        while (ind != arr[ind - 1])
        {
            int val = arr[ind - 1];
            swap(arr[ind - 1], arr[val - 1]);
            mp++;
        }
    }
    if (mp & 1)
    {
        return false;
    }
    if (mp > 2)
    {
        return false;
    }

    return true;
}