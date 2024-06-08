class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        unordered_map<int, int> mod;
        int pre = 0;
        mod.reserve(n);
        mod[0] = -1;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            pre %= k;
            if (mod.count(pre)) {
                if (i > mod[pre] + 1) {
                    return 1;
                }
            } else {
                mod[pre] = i;
            }
        }
        return 0;
    }
};