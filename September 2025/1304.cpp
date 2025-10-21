// Approach 1 : Solved 1
class Solution {
public:
    vector<int> sumZero(int n) {
        int i = 0;
        int j = n - 1;
        int start = 1;
        vector<int > res(n,0);
        while (i < j) {
            res[i] = start;
            res[j] = -start;
            i++;
            j--;
            start++;
        }
        return res;
    }
};

// Approach 2 : Solved 1
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n, 0);
        int start = 1;
        int i = 0;
        while (i + 1 < n) {
            arr[i] = start;
            arr[i + 1] = -start;
            i+=2;
            start++;
        }

        return arr;
    }
};