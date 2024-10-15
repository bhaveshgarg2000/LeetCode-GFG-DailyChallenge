class Solution
{
public:
    long long minimumSteps(string s)
    {
        int n = s.size();
        int index = 0;
        long count = 0;

        while (index < n && s[index] != '1')
        {
            index++;
        }

        for (int i = index; i < n; i++)
        {
            if (s[i] == '0')
            {
                count += i - index;
                index++;
            }
        }
        return count;
    }
};