//  Here in this we just are moving all the non-zero elements to the front of the array and then filling the rest of the array with zeros. This is done in a single pass through the array, making it an efficient solution.
// T.C : O(n) and S.C: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }
        while (i < n) {
            nums[i] = 0;
            i++;
        }
    }
};



//  Here in this case we are creating a copy of the original array and then moving all the non-zero elements to the front of the new array and then filling the rest of the array with zeros. This is done in two passes through the array, making it less efficient than the previous solution.
// T.C : O(n) and S.C: O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> copyArr;
        vector<int> numsArr;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) {
                copyArr.push_back(nums[j]);
            } else {
                numsArr.push_back(nums[j]);
            }
        }
        numsArr.insert(numsArr.end(), copyArr.begin(), copyArr.end());
        nums = numsArr;
    }
};


// Here in this case we are using the two-pointer technique to move all the non-zero elements to the front of the array and then filling the rest of the array with zeros. This is done in a single pass through the array, making it an efficient solution.
// T.C : O(n) and S.C: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};