class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    static bool compare(Item &a, Item &b)
    {
        float aVal = 1.0 * a.value / a.weight;
        float bVal = 1.0 * b.value / b.weight;
        return aVal > bVal;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0;
        sort(arr, arr + n, compare);
        for (int i = 0; i < n; i++)
        {
            int take = min(W, arr[i].weight);
            double val = 1.0 * arr[i].value / arr[i].weight;
            ans += take * val;
            W -= take;
        }
        return ans;
    }
};