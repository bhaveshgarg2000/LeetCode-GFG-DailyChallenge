class Solution
{
public:
    string maximumOddBinaryNumber(string &s)
    {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        if (s[right] != '1')
        {
            while (s[left] != '1' && left < right)
            { // Added a condition to prevent left from surpassing right
                left++;
            }
            swap(s[left], s[right]); // Moved swap inside the loop
        }
        left = 0;
        right = n - 2;
        while (left < right)
        {
            while (left < n && s[left] == '1')
            {
                left++;
            }
            while (right >= 0 && s[right] == '0')
            {
                right--;
            }
            if (left < right)
            {
                swap(s[left], s[right]);
            }
        }
        return s;
    }
};
