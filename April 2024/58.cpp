class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size(); // Get the size of the input string
        int ans = 0;      // Initialize the answer variable to 0
        for (int i = n - 1; i >= 0; i--)
        { // Start iterating from the end of the string
            if (ans > 0 && s[i] == ' ')
            {          // If we have encountered characters before and find a space
                break; // Exit the loop since we have found the last word
            }
            if (s[i] != ' ')
            {          // If the current character is not a space
                ans++; // Increment the length of the last word
            }
        }
        return ans; // Return the length of the last word
    }
};
