class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0; // Initialize the depth counter
        int open = 0;  // Initialize the count of open parentheses
        for (auto c : s)
        {
            if (c == '(')
            {
                open++; // Increment open count when encountering an open parenthesis
            }
            if (c == ')')
            {
                open--; // Decrement open count when encountering a closing parenthesis
            }
            depth = max(depth, open); // Update the maximum depth encountered so far
        }
        return depth; // Return the maximum depth of parentheses
    }
};