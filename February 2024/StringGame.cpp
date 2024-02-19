class Solution
{
public:
    int minValue(string s, int k)
    {
        // code here
        map<char, int> m;

        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }

        vector<int> v;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            v.push_back((*it).second);
        }

        sort(v.begin(), v.end());
        while (k != 0)
        {
            v[v.size() - 1] = v[v.size() - 1] - 1;
            k--;
            sort(v.begin(), v.end());
        }
        long long sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum = sum + v[i] * v[i];
        }
        return sum;
    }
};