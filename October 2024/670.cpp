class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        for (int i = 0; i < s.length(); i++)
        {
            int n = s[i] - '0';
            int idx = i + 1;
            for (int j = i + 1; j < s.length(); j++)
            {
                int m = s[j] - '0';
                if (n <= m)
                {
                    n = m;
                    idx = j;
                }
            }
            if (n > s[i] - '0')
            {
                swap(s[i], s[idx]);
                break;
            }
        }
        return stoi(s);
    }
};