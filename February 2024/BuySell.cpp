int maxProfit(vector<int> &price)
{
    int n = price.size();
    vector<int> leftProfit(n), rightProfit(n);

    int minPrice = price[0];
    for (int i = 1; i < n; i++)
    {
        minPrice = min(minPrice, price[i]);
        leftProfit[i] = max(leftProfit[i - 1], price[i] - minPrice);
    }

    int maxPrice = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxPrice = max(maxPrice, price[i]);
        rightProfit[i] = max(rightProfit[i + 1], maxPrice - price[i]);
    }

    int maxTotalProfit = 0;
    for (int i = 0; i < n; i++)
        maxTotalProfit = max(maxTotalProfit, leftProfit[i] + rightProfit[i]);

    return maxTotalProfit;
}