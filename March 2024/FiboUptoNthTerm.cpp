class Solution
{
public:
    vector<int> Series(int n)
    {
        vector<int> v;
        v.push_back(0);
        v.push_back(1);

        if (n <= 1)
        {
            return v;
        }

        long long int mod = pow(10, 9) + 7;

        for (long long int i = 0; i < n - 1; i++)
        {

            v.push_back((v[i] + v[i + 1]) % mod);
        }

        return v;
    }
};