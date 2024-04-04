class Solution
{
public:
    // Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s)
    {
        long long sum = 0;
        long long cont = 0;

        int mod = 1000000007;

        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            cont = (cont * 10 + (i + 1) * (s[i] - '0')) % mod;
            sum = (sum + cont) % mod;
        }
        return sum;
    }
};