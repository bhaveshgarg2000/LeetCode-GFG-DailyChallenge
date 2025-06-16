class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int t = original.size();
        if (t != m * n) {
            return {};
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int i = 0;
        int j = 0;

        for (int k = 0; k < t; k++) {
            ans[i][j] = original[k];
            if (j == n - 1) {
                j = 0;
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};