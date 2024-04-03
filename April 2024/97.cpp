class Solution
{
private:
    // Helper function for recursive search
    bool search(int index, int i, int j, vector<vector<char>> &board, string word)
    {
        // If we have matched the entire word, return true
        if (index == word.size())
        {
            return true;
        }

        // Check if current position is out of bounds
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        {
            return false;
        }

        bool ans = false;

        // Check if the current character matches the word's character
        if (word[index] == board[i][j])
        {
            // Mark the current position as visited by changing the character to '*'
            board[i][j] = '*';

            // Recursively search in all four directions
            ans = search(index + 1, i + 1, j, board, word) || // Down
                  search(index + 1, i, j + 1, board, word) || // Right
                  search(index + 1, i - 1, j, board, word) || // Up
                  search(index + 1, i, j - 1, board, word);   // Left

            // Restore the original character after the recursive calls
            board[i][j] = word[index];
        }

        return ans;
    }

public:
    // Main function to check if the word exists on the board
    bool exist(vector<vector<char>> &board, string word)
    {
        // row
        int n = board.size();
        // col
        int m = board[0].size();
        int index = 0;
        // Iterate through each cell on the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Check if the first character of the word matches the current cell
                if (word[index] == board[i][j])
                {
                    // If search starting from this position is successful, return true
                    if (search(index, i, j, board, word))
                    {
                        return true;
                    }
                }
            }
        }

        // If no match is found, return false
        return false;
    }
};
