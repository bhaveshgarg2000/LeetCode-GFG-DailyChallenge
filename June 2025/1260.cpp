class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int newVal = ((i * m + j) + k) % (n * m);
                int newR = newVal / m;
                int newC = newVal % m;

                temp[newR][newC] = grid[i][j];
            }
        }
        return temp;
    }
};