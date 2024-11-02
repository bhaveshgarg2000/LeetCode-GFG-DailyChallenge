class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        // Get the length of the sentence
        int n = sentence.length();

        // Check if the first character matches the last character
        // If they are not the same, the sentence is not circular
        if (sentence[0] != sentence[n - 1])
        {
            return false;
        }

        // Loop through the sentence, starting from the second character to the
        // second-last character
        for (int i = 1; i < n - 1; i++)
        {
            // Check if the current character is a space
            if (sentence[i] == ' ')
            {
                // If the character before and after the space are not the same,
                // it's not circular
                if (sentence[i - 1] != sentence[i + 1])
                {
                    return false;
                }
            }
        }

        // If all checks are passed, the sentence is circular
        return true;
    }
};
