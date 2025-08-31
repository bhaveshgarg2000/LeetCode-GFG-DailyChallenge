class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();       // Number of rows
        int m = mat[0].size();    // Number of columns
        
        map<int, vector<int>> mpp;  // Map to group elements with same i+j (diagonal identifier)
        vector<int> res;            // Result vector to store the final diagonal order

        // Step 1: Group elements by their diagonal index (i + j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mpp[i + j].push_back(mat[i][j]);  // Group by diagonal index
            }
        }

        bool flip = true;  // Used to reverse alternate diagonals for correct traversal order

        // Step 2: Traverse the map to build the result in zig-zag diagonal order
        for (auto& it : mpp) {
            if (flip) {
                reverse(it.second.begin(), it.second.end());  // Reverse every alternate diagonal
            }
            for (int& num : it.second) {
                res.push_back(num);  // Append elements to result
            }
            flip = !flip;  // Flip the direction for next diagonal
        }

        return res;  // Return the final diagonal traversal
    }
};
