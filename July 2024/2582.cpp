class Solution {
public:
    int passThePillow(int n, int time) {
        if (time < n) {
            return 1 + time;
        }
        int x = time % (n - 1);
        int y = time / (n - 1);
        if (y % 2 != 0) {
            return n - x;
        }

        return 1 + x;
    }
};