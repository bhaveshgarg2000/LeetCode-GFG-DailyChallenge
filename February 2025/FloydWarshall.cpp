class Solution
{
public:
    void shortestDistance(vector<vector<int>> &mat)
    {
        // Get the number of nodes in the graph
        int n = mat.size();

        // Step 1: Initialize the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the distance is -1, it means there is no direct path between nodes
                // Replace it with a large value (1e9) to represent "infinity"
                if (mat[i][j] == -1)
                {
                    mat[i][j] = 1e9;
                }
                // The distance from a node to itself is always 0
                if (i == j)
                {
                    mat[i][j] = 0;
                }
            }
        }

        // Step 2: Apply the Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++)
        { // Intermediate node
            for (int i = 0; i < n; i++)
            { // Source node
                for (int j = 0; j < n; j++)
                { // Destination node
                    // Update the shortest path from i to j via k
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        // Step 3: Convert "infinity" values back to -1 for unreachable nodes
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1e9)
                {
                    mat[i][j] = -1;
                }
            }
        }
    }
};
