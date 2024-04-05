class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int n = num.size();
        string good = "";
        for (int i = 0; i + 2 < n; i++)
        {
            // 0 and 1 mapping && 1 and 2 maaping && 1 and 3 mapping
            if (num[i] == num[i + 1] and num[i + 1] == num[i + 2] and num[i] == num[i + 2])
            {
                string temp = "";
                // substring of size 3
                temp = num.substr(i, 3);
                // substring of max no
                good = max(good, temp);
            }
        }
        // return good subsstr
        return good;
    }
};