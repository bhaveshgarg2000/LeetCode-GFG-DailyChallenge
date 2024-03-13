class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; i++) {
            long long left = (i * (i + 1))/2;
            long long right = (n * (n + 1))/2 - (i * (i - 1))/2;
            if(left == right){
                return i;
            }
        }
        return -1;
    }
};