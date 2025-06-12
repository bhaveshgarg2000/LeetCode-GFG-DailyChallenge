class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (auto& it : image) {
            reverse(it.begin(), it.end());
            for (auto& i : it) {
                i ^= 1;
            }
        }
        return image;
    }
};