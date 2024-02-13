class Solution
{
public:
    bool palindrome(string &str)
    {
        int i = 0;
        int j = str.length() - 1;
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string firstPalindrome(vector<string> &words)
    {
        string ans = ""; // Corrected the return type to string
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (palindrome(words[i]))
            {
                ans = words[i]; // Store the palindrome and break the loop
                break;
            }
        }
        return ans;
    }
};
